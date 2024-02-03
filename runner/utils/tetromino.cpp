#include "tetromino.h"
#include "utils.h"

#include <cctype>
#include <string>

using namespace std;

Tetromino::Tetromino(const TetrominoInitializeParams &params) {
  this->_rotation = params.initialRotation;
  this->symbol = params.symbol;

  string symbol(1, tolower(params.symbol));

  json tetromino = tetrominoes[symbol];

  this->states = tetromino["matrix"]["data"];

  this->location = {
      floor((double)params.boardWidth / 2 - (double)tetromino["matrix"]["w"] / 2),
      params.boardHeight + 2,
  };
}

vector<pair<int, int>> Tetromino::getBlocks() {
  return this->states[this->getRotation()];
}
vector<pair<int, int>> Tetromino::getAbsoluteBlocks() {
  auto blocks = this->getBlocks();

  for (int i = 0; i < blocks.size(); i++) {
    blocks[i].first += this->location.first;
    blocks[i].second = -blocks[i].second + this->location.second;
  }

  return blocks;
}

int Tetromino::getRotation() { return this->_rotation % 4; }

void Tetromino::setRotation(int rotation) { this->_rotation = rotation % 4; }

KickRes Tetromino::rotate(vector<vector<char>> &board, KickTable kicktable,
                          int amt) {
  vector<pair<int, int>> rotatedBlocks =
      this->states[(this->getRotation() + amt) % 4];

  KickRes kickRes =
      performKick(kicktable, this->symbol, this->location, rotatedBlocks,
                  this->getRotation(), (this->getRotation() + amt) % 4, board);

  if (kickRes.id != "") {
    this->location.first += kickRes.kick.first;
    this->location.second -= kickRes.kick.second;
  }
  if (kickRes.success) {
    this->setRotation((this->getRotation() + amt));
  }

  return kickRes;
}

KickRes Tetromino::rotateCW(vector<vector<char>> &board, KickTable kicktable) {
  return this->rotate(board, kicktable, 1);
}

KickRes Tetromino::rotateCCW(vector<vector<char>> &board, KickTable kicktable) {
  return this->rotate(board, kicktable, 3);
}

KickRes Tetromino::rotate180(vector<vector<char>> &board, KickTable kicktable) {
  return this->rotate(board, kicktable, 2);
}

bool Tetromino::moveRight(vector<vector<char>> &board) {
  this->location.first++;
  if (!legal(this->getAbsoluteBlocks(), board)) {
    this->location.first--;
    return false;
  }
  return true;
}

bool Tetromino::moveLeft(vector<vector<char>> &board) {
  this->location.first--;
  if (!legal(this->getAbsoluteBlocks(), board)) {
    this->location.first++;
    return false;
  }
  return true;
}

void Tetromino::softDrop(vector<vector<char>> &board) {
  while (legal(this->getAbsoluteBlocks(), board)) {
    this->location.second--;
  }
  this->location.second++;
}