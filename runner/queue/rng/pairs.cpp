#include "pairs.h"

RngInnerFunction pairs(int seed) {
  RNG gen = RNG(seed);
  vector<char> TETROMINOS = {'Z', 'L', 'O', 'S', 'I', 'J', 'T'};
  return [gen, TETROMINOS]() mutable -> vector<char> {
    vector<char> result = gen.shuffleArray(TETROMINOS);
    vector<char> pairs = {
        result[0], result[0], result[0], result[1], result[1], result[1],
    };
    return gen.shuffleArray(pairs);
  };
}