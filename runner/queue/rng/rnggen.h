#pragma once

#include <cmath>
#include <functional>
#include <vector>

using namespace std;

class RNG {
 public:
  RNG(long seed) {
    t = seed % 2147483647;
    if (t <= 0) {
      t += 2147483646;
    }
  }
  RNG() = default;

  long next() { return t = (16807 * t) % 2147483647; }

  double nextFloat() { return (double)(this->next() - 1) / 2147483646; }

  template <typename T>
  vector<T> shuffleArray(vector<T> array) {
    if (array.size() == 0) {
      return array;
    }

    for (int i = array.size() - 1; i != 0; i--) {
      int r = floor(this->nextFloat() * (i + 1));
      swap(array[i], array[r]);
    }

    return array;
  }

 private:
  long t;
};

typedef function<vector<char>()> RngInnerFunction;
typedef function<function<vector<char>()>(int seed)>
    RngFunction;
