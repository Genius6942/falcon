#include "totalMayhem.h"

RngInnerFunction totalMayhem(int seed) {
  RNG gen = RNG(seed);
  vector<char> TETROMINOS = {'Z', 'L', 'O', 'S', 'I', 'J', 'T'};
  return [gen, TETROMINOS]() mutable -> vector<char> {
    int index = floor(gen.nextFloat() * TETROMINOS.size());
    return {TETROMINOS[index]};
  };
}