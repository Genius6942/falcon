#include "bag14.h"

RngInnerFunction bag14(int seed) {
  RNG gen = RNG(seed);
  vector<char> TETROMINOS = {
      'Z', 'L', 'O', 'S', 'I', 'J', 'T', 'Z', 'L', 'O', 'S', 'I', 'J', 'T',
  };
  return [gen, TETROMINOS]() mutable -> vector<char> {
    return gen.shuffleArray(TETROMINOS);
  };
}