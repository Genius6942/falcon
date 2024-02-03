#pragma once

#include <vector>

#include "kicks.h"
#include "tetrominoData.h"
#include "utils.h"

using namespace std;

struct TetrominoInitializeParams {
  char symbol;
  int initialRotation;
  int boardHeight;
  int boardWidth;
};

class Tetromino {
 public:
  Tetromino(const TetrominoInitializeParams &params);
  Tetromino() = default;

  char symbol;
  vector<vector<pair<int, int>>> states;
  pair<int, int> location;

  vector<pair<int, int>> getBlocks();
  vector<pair<int, int>> getAbsoluteBlocks();

  int getRotation();
  void setRotation(int rotation);
  KickRes rotate(vector<vector<char>> &board, KickTable kicktable, int amt);
  KickRes rotateCW(vector<vector<char>> &board, KickTable kicktable);
  KickRes rotateCCW(vector<vector<char>> &board, KickTable kicktable);
  KickRes rotate180(vector<vector<char>> &board, KickTable kicktable);
  bool moveRight(vector<vector<char>> &board);
  bool moveLeft(vector<vector<char>> &board);

  void softDrop(vector<vector<char>> &board);

 private:
  int _rotation;
};