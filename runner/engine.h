// engine.h
#pragma once

#include <optional>
#include <string>
#include <tuple>
#include <vector>

#include "board.h"
#include "garbage.h"
#include "queue/queue.h"
#include "utils/utils.h"

using namespace std;

struct GameOptions {
  string spinBonuses;
  string comboTable;
  bool b2bChaining;
  string garbageTargetBonus;
  struct GarbageMultiplierOptions {
    double value;
    double increase;
    int marginTime;
  };

  GarbageMultiplierOptions garbageMultiplier;

  int garbageAttackCap;
  string garbageBlocking;
};

struct LastSpin {
  char piece;
  string type;
};

struct Stats {
  int b2b;
  int combo;
};

namespace EngineConfig {

  struct EngineInitializeParams {
    QueueInitializeParams queue;
    BoardInitializeParams board;
    string kickTable;
    GameOptions options;
    GarbageQueueInitializeParams garbage;
  };

  inline void to_json(json &j, const EngineInitializeParams &val) {
    j = json{{"queue",
              {{"seed", val.queue.seed},
               {"type", val.queue.type},
               {"minLength", val.queue.minLength}}},
             {"board",
              {{"width", val.board.width},
               {"height", val.board.height},
               {"buffer", val.board.buffer}}},
             {"kickTable", val.kickTable},
             {"options",
              {{"spinBonuses", val.options.spinBonuses},
               {"comboTable", val.options.comboTable},
               {"b2bChaining", val.options.b2bChaining},
               {"garbageTargetBonus", val.options.garbageTargetBonus},
               {"garbageMultiplier",
                {{"value", val.options.garbageMultiplier.value},
                 {"increase", val.options.garbageMultiplier.increase},
                 {"marginTime", val.options.garbageMultiplier.marginTime}}},
               {"garbageAttackCap", val.options.garbageAttackCap},
               {"garbageBlocking", val.options.garbageBlocking}}},
             {"garbage",
              {{"cap",
                {{"value", val.garbage.cap.value},
                 {"absolute", val.garbage.cap.absolute},
                 {"max", val.garbage.cap.max},
                 {"increase", val.garbage.cap.increase}}},
               {"speed", val.garbage.speed}}}};
  }
  inline void from_json(const json &j, EngineInitializeParams &val) {
    val.queue.seed = j.at("queue").at("seed").get<decltype(val.queue.seed)>();
    val.queue.type = j.at("queue").at("type").get<decltype(val.queue.type)>();
    val.queue.minLength =
        j.at("queue").at("minLength").get<decltype(val.queue.minLength)>();

    val.board.width =
        j.at("board").at("width").get<decltype(val.board.width)>();
    val.board.height =
        j.at("board").at("height").get<decltype(val.board.height)>();
    val.board.buffer =
        j.at("board").at("buffer").get<decltype(val.board.buffer)>();

    val.kickTable = j.at("kickTable").get<decltype(val.kickTable)>();

    val.options.spinBonuses = j.at("options")
                                  .at("spinBonuses")
                                  .get<decltype(val.options.spinBonuses)>();
    val.options.comboTable = j.at("options")
                                 .at("comboTable")
                                 .get<decltype(val.options.comboTable)>();
    val.options.b2bChaining = j.at("options")
                                  .at("b2bChaining")
                                  .get<decltype(val.options.b2bChaining)>();
    val.options.garbageTargetBonus =
        j.at("options")
            .at("garbageTargetBonus")
            .get<decltype(val.options.garbageTargetBonus)>();

    val.options.garbageMultiplier.value =
        j.at("options")
            .at("garbageMultiplier")
            .at("value")
            .get<decltype(val.options.garbageMultiplier.value)>();
    val.options.garbageMultiplier.increase =
        j.at("options")
            .at("garbageMultiplier")
            .at("increase")
            .get<decltype(val.options.garbageMultiplier.increase)>();
    val.options.garbageMultiplier.marginTime =
        j.at("options")
            .at("garbageMultiplier")
            .at("marginTime")
            .get<decltype(val.options.garbageMultiplier.marginTime)>();

    val.options.garbageAttackCap =
        j.at("options")
            .at("garbageAttackCap")
            .get<decltype(val.options.garbageAttackCap)>();
    val.options.garbageBlocking =
        j.at("options")
            .at("garbageBlocking")
            .get<decltype(val.options.garbageBlocking)>();

    val.garbage.cap.value = j.at("garbage")
                                .at("cap")
                                .at("value")
                                .get<decltype(val.garbage.cap.value)>();
    val.garbage.cap.absolute = j.at("garbage")
                                   .at("cap")
                                   .at("absolute")
                                   .get<decltype(val.garbage.cap.absolute)>();
    val.garbage.cap.max = j.at("garbage")
                              .at("cap")
                              .at("max")
                              .get<decltype(val.garbage.cap.max)>();
    val.garbage.cap.increase = j.at("garbage")
                                   .at("cap")
                                   .at("increase")
                                   .get<decltype(val.garbage.cap.increase)>();

    val.garbage.speed =
        j.at("garbage").at("speed").get<decltype(val.garbage.speed)>();
  }

}  // namespace EngineConfig

using EngineInitializeParams = EngineConfig::EngineInitializeParams;

struct EngineCheckpoint {
  vector<Garbage> garbage;
  int queue;
  vector<vector<char>> board;
  char falling;
  optional<char> hold;
};

struct HardDropRes {
  int lines;
  string spin;
  int sent;
  bool garbageAdded;
};

class Engine {
 public:
  // Define your Board class members and methods here
  Engine(EngineInitializeParams options);
  Engine() = default;

  Queue queue;

  optional<char> held;

  Tetromino falling;
  string kickTableName;
  Board board;

  LastSpin lastSpin;
  Stats stats;

  GameOptions gameOptions;

  GarbageQueue garbageQueue;

  int frame;

  vector<EngineCheckpoint> checkpoints;

  void revert();

  void checkpoint();

  void save();

  auto getKickTable();

  void nextPiece();

  void initiatePiece(char piece);

  bool isTSpinKick(KickRes kick);

  void rotateCW();
  void rotateCCW();
  void rotate180();

  void moveLeft();
  void moveRight();

  void softDrop();

  string detectSpin(bool finOrTst);

  string detectTSpin(bool finOrTst);

  vector<bool> getTCorners();

  HardDropRes hardDrop();

  void recieveGarbage(vector<Garbage>);

  void hold();

  json getPreview(char piece);

  vector<string> bfs(int depth, vector<pair<int, int>> target);

  void onQueuePieces(void (*listener)(vector<char> pieces));
};