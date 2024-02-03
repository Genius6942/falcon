// board.cpp
#include "board.h"

#include <algorithm>

Board::Board(BoardInitializeParams options)
    : width(options.width),
      height(options.height),
      buffer(options.buffer),
      state(height + buffer, vector<char>(width, 'X')) {}

int Board::fullHeight() const { return height + buffer; }

void Board::add(const vector<tuple<char, int, int>> &blocks) {
  for (const auto &block : blocks) {
    auto [item, x, y] = block;
    state[y][x] = item;
  }
}

int Board::clearLines() {
  vector<int> lines;
  for (int idx = 0; idx < state.size(); ++idx) {
    if (all_of(state[idx].begin(), state[idx].end(),
               [](char block) { return block != 'X'; })) {
      lines.push_back(idx);
    }
  }

  for (auto it = lines.rbegin(); it != lines.rend(); ++it) {
    state.erase(state.begin() + *it);
    state.push_back(vector<char>(width, 'X'));
  }

  return lines.size();
}

bool Board::perfectClear() const {
  return all_of(state.begin(), state.end(), [](const vector<char> &row) {
    return all_of(row.begin(), row.end(),
                  [](char block) { return block == 'X'; });
  });
}

void Board::insertGarbage(int amount, int size, int column) {
  state.insert(state.begin(), amount, vector<char>(width, 'X'));

  state.erase(state.begin() + fullHeight() - amount, state.end());
  for (int i = 0; i < amount; ++i) {
    fill(state[i].begin() + column, state[i].begin() + column + size, 'X');
    fill(state[i].begin(), state[i].begin() + column, 'G');
  }
}
