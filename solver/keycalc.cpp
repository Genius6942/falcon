#include "keycalc.h"

#include <algorithm>
#include <string>

struct EngineState {
  int rotation;
  pair<int, int> location;
};

vector<KeyResult> keycalc(Engine *engine) {
  auto pressKey = [&engine](string key) {
    if (key == "left") {
      engine->moveLeft();
    } else if (key == "right") {
      engine->moveRight();
    } else if (key == "ccw") {
      engine->rotateCCW();
    } else if (key == "cw") {
      engine->rotateCW();
    } else if (key == "180") {
      engine->rotate180();
    } else if (key == "soft") {
      engine->softDrop();
    }
  };

	// start with empty because we never add the no keys possibility
  vector<vector<string>> keys = {{}};

  EngineState originalState;
  originalState.rotation = engine->falling.getRotation();
  originalState.location = make_pair(engine->falling.location.first,
                                     engine->falling.location.second);

  auto reset = [&engine, &originalState]() {
    engine->falling.setRotation(originalState.rotation);
    engine->falling.location = originalState.location;
  };


  for (string rot : {"", "cw", "ccw", "180"}) {
    if (engine->falling.symbol == 'O' && rot != "")
      continue;
    if (engine->falling.symbol == 'I' && rot == "180" || rot == "ccw")
      continue;
    if (engine->falling.symbol == 'S' && rot == "180" || rot == "ccw")
      continue;
    if (engine->falling.symbol == 'Z' && rot == "180" || rot == "ccw")
      continue;

    if (rot.length() > 0) {
      pressKey(rot);
    }

    vector<pair<int, int>> blocks = engine->falling.getBlocks();

    int left =
        min_element(blocks.begin(), blocks.end(),
                    [](const pair<int, int> &a, const pair<int, int> &b) {
                      return a.first < b.first;
                    })
            ->first +
        engine->falling.location.first;

    int right =
        engine->board.width -
        (max_element(blocks.begin(), blocks.end(),
                     [](const pair<int, int> &a, const pair<int, int> &b) {
                       return a.first < b.first;
                     })
             ->first +
         engine->falling.location.first - 1);

    string d1;
    for (auto b : blocks) {
      d1 = d1 + "(" + to_string(b.first) + ", " + to_string(b.second) + "), ";
    }
    for (int i = 0; i < left; i++) {
      if (rot.length() == 0 && i == 0)
        continue;
      vector<string> k;
      if (rot.length() > 0) {
        k.push_back(rot);
      }

      for (int j = 0; j < i; j++) {
        k.push_back("left");
      }
      keys.push_back(k);
    }

    for (int i = 1; i < right; i++) {

      vector<string> k;
      if (rot.length() > 0) {
        k.push_back(rot);
      }

      for (int j = 0; j < i; j++) {
        k.push_back("right");
      }
      keys.push_back(k);
    }
    reset();
  }

  vector<KeyResult> preres;
  for (auto k : keys) {
    string s = "";
    for (auto key : k) {
      pressKey(key);
      s += key + ", ";
    }
    pressKey("soft");



    KeyResult r;
    r.keys = k;
    r.board = engine->board.state;
    r.holes = 0;
    

    // add falling to board
    vector<pair<int, int>> blocks = engine->falling.getBlocks();
    for (auto block : blocks) {
      r.board[block.second][block.first + engine->falling.location.first] =
          engine->falling.symbol;
    }

    // calculate holes yay
    for (auto block : blocks) {
      int holes = 0;
      for (int i = block.second - 1; i >= 0; i--) {
        if (r.board[i][block.first + engine->falling.location.first]) {
          break;
        } else {
          holes++;
        }
      }

      r.holes += holes;
    }

    preres.push_back(r);
  }

  int min_holes =
      min_element(preres.begin(), preres.end(), [](KeyResult a, KeyResult b) {
        return a.holes < b.holes;
      })->holes;

  vector<KeyResult> res;

  for (auto &e : preres) {
    if (e.holes == min_holes) {
      res.push_back(e);
    }
  }

  return res;
}