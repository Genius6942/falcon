#include "engine.h"

#include "search/search.h"
#include <iostream>

using namespace std;

Engine::Engine(EngineInitializeParams options) {
  this->queue = Queue(options.queue);

  this->kickTableName = options.kickTable;

  this->board = Board(options.board);

  this->garbageQueue = GarbageQueue(options.garbage);

  this->nextPiece();

  this->held = nullopt;

  this->lastSpin.piece = 'X';
  this->lastSpin.type = "none";

  this->stats.b2b = -1;
  this->stats.combo = -1;

  this->gameOptions = options.options;

  this->frame = 0;

  this->checkpoints = {};
}

void Engine::revert() {
  if (this->checkpoints.size() == 0) {
    return;
  }

  EngineCheckpoint checkpoint = this->checkpoints.back();
  this->checkpoints.pop_back();
  this->garbageQueue.queue = checkpoint.garbage;
  this->queue.index = checkpoint.queue;
  this->board.state = checkpoint.board;
  this->held = checkpoint.hold;
  this->initiatePiece(checkpoint.falling);
}

void Engine::checkpoint() { this->save(); }

void Engine::save() {
  EngineCheckpoint checkpoint;
  checkpoint.garbage = this->garbageQueue.queue;
  checkpoint.queue = this->queue.index;
  checkpoint.board = this->board.state;
  checkpoint.falling = this->falling.symbol;
  checkpoint.hold = this->held;
  this->checkpoints.push_back(checkpoint);
}

auto Engine::getKickTable() {
  auto res = kickData[this->kickTableName];
  return res;
}

void Engine::nextPiece() { this->initiatePiece(this->queue.shift()); }

void Engine::initiatePiece(char piece) {
  TetrominoInitializeParams params;
  params.symbol = piece;
  params.boardHeight = this->board.height;
  params.boardWidth = this->board.width;
  string pieceString(1, piece);
  bool customInitialRotation =
      this->getKickTable()["spawn_rotation"].contains(pieceString);
  if (customInitialRotation) {
    params.initialRotation =
        (int)this->getKickTable()["spawn_rotation"][pieceString];
  } else {
    params.initialRotation = 0;
  }
  this->falling = Tetromino(params);
}

bool Engine::isTSpinKick(KickRes kick) {
  if (!kick.success || kick.id == "" || kick.index == -1) return false;
  return (kick.id == "03" && kick.index == 3) ||
         (kick.id == "21" && kick.index == 3);
}

string Engine::detectSpin(bool finOrTst) {
  if (this->falling.symbol == 'T') {
    return this->detectTSpin(finOrTst);
  }
  return "none";
}

string Engine::detectTSpin(bool finOrTst) {
  if (this->falling.symbol != 'T') {
    return "none";
  }
  if (finOrTst) return "normal";
  vector<bool> corners = this->getTCorners();

  // if # of corners that are true < 3 return "none"
  int numCorners = 0;
  for (int i = 0; i < corners.size(); i++) {
    if (corners[i]) numCorners++;
  }
  if (numCorners < 3) return "none";

  if (corners[this->falling.getRotation()] &&
      corners[this->falling.getRotation() + 1]) {
    return "normal";
  }

  return "mini";
}

vector<bool> Engine::getTCorners() {
  int x = this->falling.location.first + 1;
  int y = this->falling.location.second - 1;

  auto getLocation = [this](int x, int y) {
    if (x < 0 || x >= this->board.width || y < 0 || y >= this->board.height)
      return false;
    return this->board.state[y][x] == 'X';
  };

  return {getLocation(x - 1, y + 1), getLocation(x + 1, y + 1),
          getLocation(x + 1, y - 1), getLocation(x - 1, y - 1)};
}

void Engine::rotateCW() {
  LastSpin lastSpin;
  lastSpin.piece = this->falling.symbol;
  lastSpin.type = this->detectSpin(this->isTSpinKick(
      this->falling.rotateCW(this->board.state, this->kickTableName)));
  this->lastSpin = lastSpin;
}

void Engine::rotateCCW() {
  LastSpin lastSpin;
  lastSpin.piece = this->falling.symbol;
  lastSpin.type = this->detectSpin(this->isTSpinKick(
      this->falling.rotateCCW(this->board.state, this->kickTableName)));
  this->lastSpin = lastSpin;
}

void Engine::rotate180() {
  LastSpin lastSpin;
  lastSpin.piece = this->falling.symbol;
  lastSpin.type = this->detectSpin(this->isTSpinKick(
      this->falling.rotate180(this->board.state, this->kickTableName)));
  this->lastSpin = lastSpin;
}

void Engine::moveLeft() { this->falling.moveLeft(this->board.state); }

void Engine::moveRight() { this->falling.moveRight(this->board.state); }

void Engine::softDrop() { this->falling.softDrop(this->board.state); }

HardDropRes Engine::hardDrop() {
  this->softDrop();

  std::vector<std::tuple<char, int, int>> blocks;

  auto b = this->falling.getAbsoluteBlocks();
  for (auto block : b) {
    blocks.push_back(
        make_tuple(this->falling.symbol, block.first, block.second));
  }

  this->board.add(blocks);

  int lines = this->board.clearLines();

  if (lines > 0) {
    this->stats.combo++;
    if ((this->lastSpin.type != "none") || lines >= 4) {
      this->stats.b2b++;
    } else {
      this->stats.b2b = -1;
    }
  } else {
    this->stats.combo = -1;
  }

  HardDropRes res;

  res.lines = lines;
  res.spin = this->lastSpin.type;

  GarbageCalcData garbageData;
  garbageData.lines = lines;
  garbageData.spin = this->lastSpin.type;
  garbageData.piece = this->falling.symbol;
  garbageData.b2b = this->stats.b2b;
  garbageData.combo = this->stats.combo;
  garbageData.enemies = 0;
  garbageData.perfectClear = this->board.perfectClear();
  garbageData.frame = this->frame;

  GarbageCalcConfig garbageConfig;
  garbageConfig.spinBonuses = this->gameOptions.spinBonuses;
  garbageConfig.comboTable = this->gameOptions.comboTable;
  garbageConfig.b2bChaining = this->gameOptions.b2bChaining;
  garbageConfig.garbageTargetBonus = this->gameOptions.garbageTargetBonus;
  garbageConfig.garbageMultiplier.increase =
      this->gameOptions.garbageMultiplier.increase;
  garbageConfig.garbageMultiplier.marginTime =
      this->gameOptions.garbageMultiplier.marginTime;
  garbageConfig.garbageMultiplier.value =
      this->gameOptions.garbageMultiplier.value;
  garbageConfig.garbageAttackCap = this->gameOptions.garbageAttackCap;
  garbageConfig.garbageBlocking = this->gameOptions.garbageBlocking;

  res.sent = garbageCalcV2(garbageData, garbageConfig).garbage;

  res.garbageAdded = false;

  if (lines > 0) {
    res.sent -= this->garbageQueue.cancel(res.sent);
  } else {
    vector<Garbage> garbage = this->garbageQueue.tank(this->frame);

    res.garbageAdded = garbage.size() > 0;

    for (Garbage g : garbage) {
      this->board.insertGarbage(g.amount, g.size, g.column);
    }
  }

  this->nextPiece();

  this->lastSpin.piece = 'X';
  this->lastSpin.type = "none";

  return res;
}

void Engine::hold() {
  if (this->held.has_value()) {
    char temp = this->held.value();
    this->held = this->falling.symbol;
    this->initiatePiece(temp);
  } else {
    this->held = this->falling.symbol;
    this->nextPiece();
  }
}

void Engine::recieveGarbage(vector<Garbage> garbage) {
  this->garbageQueue.recieveGarbage(garbage);
}

json Engine::getPreview(char piece) {
  return tetrominoes[(char)tolower(piece)]["preview"];
}

void Engine::onQueuePieces(void (*listener)(vector<char> pieces)) {
  this->queue.onRepopulate(listener);
}

vector<string> Engine::bfs(int depth, vector<pair<int, int>> target) {
  return searchBfs(this, depth, target);
}