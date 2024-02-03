// board.h
#pragma once

#include <tuple>
#include <vector>

using namespace std;

// Define your BoardInitializeParams struct here
struct BoardInitializeParams {
  int width;
  int height;
  int buffer;
};
class Board {
 public:
  // Define your Board class members and methods here
  Board(BoardInitializeParams options);
  Board() = default;

  int height;
  int width;
  int buffer;

  int fullHeight() const;

  void add(const vector<tuple<char, int, int>> &blocks);

  int clearLines();
  bool perfectClear() const;

  void insertGarbage(int amount, int size, int column);
  vector<vector<char>> state;
};