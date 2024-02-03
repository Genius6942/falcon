#include "solver.h"

struct SolveState {
  vector<vector<string>> keys;
  vector<vector<char>> board;
  int depth;
  double score;
};

void pressKey(Engine *engine, string key) {
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

SolveState dfsRecursiveSolve(Engine *engine, int depth, ScoringData scoring,
                             ScoringConfig scoringConfig) {
  if (depth == 0) {
    double score = scoreEngine(scoringConfig, scoring, engine);
    SolveState res;
    res.board = engine->board.state;
    res.depth = depth;
    res.score = score;

    return res;
  }

  auto moves = keycalc(engine);
  SolveState result;
  result.score = -10000000;

  for (auto move : moves) {
    // save state
    engine->checkpoint();

    for (auto key : move.keys) {
      pressKey(engine, key);
    }

    auto res = engine->hardDrop();

    ScoringData data = scoring;

    switch (res.lines) {
      case 0:
        break;
      case 1:
        data.singles++;
        break;
      case 2:
        data.doubles++;
      case 3:
        data.triples++;
        break;
      default:
        data.quads++;
        break;
    }

		data.sent += res.sent;


    auto solve = dfsRecursiveSolve(engine, depth - 1, data, scoringConfig);
		if (depth == 5) {
			logInfo("ballingbals");
		}
    solve.keys.insert(solve.keys.begin(), move.keys);
    if (solve.score > result.score) {
      result = solve;
    }

    // go back state
    engine->revert();
  }

  return result;
}

SolveResult solve(Engine *engine, SolveConfig &config) {
  // get possible piece placements or smth
  // i have no idea wtf im doing

  int depth = 4;

  int nodes = 0;

  SolveResult optimalResult;

  ScoringConfig sConfig;

  ScoringData scoringTemplate;
	scoringTemplate.singles = scoringTemplate.doubles = scoringTemplate.triples = scoringTemplate.quads = scoringTemplate.sent = 0;

  auto result = dfsRecursiveSolve(engine, depth, scoringTemplate, sConfig);

  logInfo("Solved!");

  optimalResult.solve = result.keys[0];
  optimalResult.future = result.keys;
  optimalResult.nodes = 0;

  return optimalResult;
}
