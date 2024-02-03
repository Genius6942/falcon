#include <string>
#include <vector>

#include "../runner/engine.h"
#include "keycalc.h"
#include "scoring.h"


using namespace std;

struct SolveResult {
  int nodes;
  vector<vector<string>> future;
  vector<string> solve;
};

struct SolveConfig {
	
};

SolveResult solve(Engine *engine, SolveConfig &config);