#include <string>
#include <vector>

#include "../runner/engine.h"

using namespace std;

struct KeyResult {
  vector<string> keys;
  vector<vector<char>> board;
  int holes;
};

vector<KeyResult> keycalc(Engine *engine);