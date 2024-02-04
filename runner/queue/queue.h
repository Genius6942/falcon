#pragma once

#include <string>
#include <vector>

#include "rng/rng.h"

using namespace std;

struct QueueInitializeParams {
  int seed;
  string type;
  int minLength;
};

class Queue {
 public:
  Queue(QueueInitializeParams options);
  Queue() = default;

  int seed;
  string type;
  int minLength;
  RngInnerFunction genFunction;
  vector<char> value;
  int index;

  void reset(int idx = 0);
  void onRepopulate(void (*listener)(vector<char> pieces));
  char next();
  char at(int idx);
  char shift();
  vector<string> as_string();

  function<void(vector<char> pieces)> repopulateListener =
      [](vector<char> pieces) {};

 private:
  void repopulate();
};