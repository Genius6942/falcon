// Kick.cpp
#include "kicks.h"  // assuming kicks is defined in this header

#include <string>

#include "kickData.h"
#include "utils.h"
#include <iostream>

using namespace std;

bool legal(const Blocks &blocks, const BoardState &board) {
  if (board.empty()) return false;
  for (const auto &block : blocks) {
		cout << "check " << block.first << " " << block.second << endl;
    if (block.first < 0 || block.first >= board[0].size() || block.second < 0 ||
        board[block.second][block.first] != 'X')
      return false;
  }
  return true;
}

KickRes performKick(const KickTable &kicktable, const char &piece,
                    const pair<int, int> &pieceLocation, const Blocks &blocks,
                    int startRotation, int endRotation,
                    const BoardState &board) {
  Blocks newBlocks;
  for (const auto &block : blocks) {
    newBlocks.push_back({pieceLocation.first + block.first,
                         pieceLocation.second - block.second});
  }
  if (legal(newBlocks, board)) {
    KickRes res;
    res.id = "";
    res.index = -1;
    res.kick = {0, 0};
    res.success = true;
    return res;
  }

  string kickID = to_string(startRotation) + to_string(endRotation);
  string customKicksetID = string(1, tolower(piece)) + "_kicks";
  json table = kickData[kicktable];
  customKicksetID = table.contains(customKicksetID) ? customKicksetID : "kicks";
  json kicksetJson = table[customKicksetID][kickID].get<Blocks>();
  Blocks kickset;
  for (const auto &kick : kicksetJson) {
    kickset.push_back(make_pair(kick[0], kick[1]));
  }

  for (int i = 0; i < kickset.size(); i++) {
    Blocks newBlocks;
    for (const auto &block : blocks) {
      newBlocks.push_back(
          {pieceLocation.first + block.first + kickset[i].first,
           pieceLocation.second - block.second - kickset[i].second});
    }
    if (legal(newBlocks, board)) {
      KickRes res;
      res.success = true;
      res.id = kickID;
      res.index = i;
      res.kick = kickset[i];
      return res;
    }
  }

  KickRes res;
  res.id = "";
  res.index = -1;
  res.kick = {0, 0};
  res.success = false;
  return res;
}