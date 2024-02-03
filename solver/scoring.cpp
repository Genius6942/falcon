#include "scoring.h"

int countHoles(Engine *engine) {
  int holes = 0;
  for (int x = 0; x < engine->board.width; x++) {
    bool countHole = false;
    for (int y = engine->board.fullHeight() - 1; y >= 0; y--) {
      if (engine->board.state[y][x] != 'X') {
        countHole = true;
      } else {
        if (countHole) {
          holes++;
        }
      }
    }
  }

  return holes;
}

int getBoardHeight(Engine *engine) {
  int height = 0;
  for (int x = 0; x < engine->board.width; x++) {
    for (int y = engine->board.fullHeight() - 1; y >= 0; y--) {
      if (engine->board.state[y][x] != 'X') {
        height = max(height, y);
        break;
      }
    }
  }

  return height;
}

int c = 0;
double scoreEngine(ScoringConfig &config, ScoringData &data, Engine *engine) {
  double holes = (double)countHoles(engine) / engine->board.width /
                 engine->board.height * 10;

  c++;
  if (c < 3) {
    for (int y = engine->board.state.size() - 1; y >= 0; y--) {
      auto row = engine->board.state[y];
      string s = "";
      for (auto c : row) {
        s += (c == 'X') ? ' ' : c;
      }
      logInfo(s);
    }
    logInfo("-----------------");
  }

  int b2bgains = engine->stats.b2b > 0 ? 1 : 0;

  double boardHeight = (double)getBoardHeight(engine) / engine->board.height;

  return -holes + b2bgains + data.quads - boardHeight;
}