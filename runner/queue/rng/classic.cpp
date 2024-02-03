#include "classic.h"

RngInnerFunction classic(int seed) {
  RNG gen = RNG(seed);
  vector<char> TETROMINOS = {'Z', 'L', 'O', 'S', 'I', 'J', 'T'};
  int lastGenerated = -1;
  return [gen, lastGenerated, TETROMINOS]() mutable -> vector<char> {
    int index = floor(gen.nextFloat() * (TETROMINOS.size() + 1));
    if (index == lastGenerated || index >= TETROMINOS.size()) {
      index = floor(gen.nextFloat() * TETROMINOS.size());
    }

    lastGenerated = index;
    return {TETROMINOS[index]};
  };
}