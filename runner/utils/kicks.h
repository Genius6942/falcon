#pragma once

#include <map>
#include <string>
#include <vector>

#include "../../lib/nlohmann/json.hpp"
#include "kickData.h"

using namespace std;

using json = nlohmann::json;
using KickTable = string;
using BoardState = vector<vector<char>>;
using Block = pair<int, int>;
using Blocks = vector<Block>;
using Location = pair<int, int>;
struct KickRes {
  bool success;
  string id;
  int index;
  Location kick;
};

bool legal(const Blocks &blocks, const BoardState &board);

KickRes performKick(const KickTable &kicktable, const char &piece,
                    const pair<int, int> &pieceLocation, const Blocks &blocks,
                    int startRotation, int endRotation,
                    const BoardState &board);
