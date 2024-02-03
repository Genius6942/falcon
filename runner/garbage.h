// garbage.h

#pragma once

#include <vector>

#include "utils/utils.h"

using namespace std;

struct GarbageQueueInitializeParams {
  struct GarbageCapParams {
    int value;
    int absolute;
    int max;
    double increase;
  };
  GarbageCapParams cap;
  int speed;
};

struct Garbage {
  int frame;
  int amount;
  int size;
  int column;

  bool operator<(const Garbage &garbage) const { return frame < garbage.frame; }
};

class GarbageQueue {
 public:
  GarbageQueue(GarbageQueueInitializeParams options);
  GarbageQueue() = default;

  GarbageQueueInitializeParams options;

  vector<Garbage> queue;

  int getSize();

  int getCap(int frame);

  void recieveGarbage(vector<Garbage> garbage);

  int cancel(int amount);

  vector<Garbage> tank(int frame);
};