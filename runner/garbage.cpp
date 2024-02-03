#include "garbage.h"

#include "utils/increases.h"

using namespace std;

GarbageQueue::GarbageQueue(GarbageQueueInitializeParams options) {
  this->options = options;

  if (!this->options.cap.absolute) {
    this->options.cap.absolute = -1;
  }

  this->queue = {};
}

int GarbageQueue::getSize() {
  int size = 0;
  for (int i = 0; i < this->queue.size(); i++) {
    size += this->queue[i].amount;
  }
  return size;
}

int GarbageQueue::getCap(int frame) {
  return calculateIncrease(this->options.cap.value, frame,
                           this->options.cap.increase, 0);
}

void GarbageQueue::recieveGarbage(vector<Garbage> garbage) {
  for (int i = 0; i < garbage.size(); i++) {
    this->queue.push_back(garbage[i]);
  }

  while (this->getSize() > this->options.cap.absolute) {
    int total = this->getSize();
    if (this->queue[this->queue.size() - 1].amount <=
        total - this->options.cap.absolute) {
      this->queue.pop_back();
    } else {
      this->queue[this->queue.size() - 1].amount -=
          total - this->options.cap.absolute;
    }
  }
}

int GarbageQueue::cancel(int amount) {
  int newAmount = amount;
  while (newAmount > 0) {
    if (this->queue.size() == 0) {
      break;
    }

    if (newAmount >= this->queue[0].amount) {
      newAmount -= this->queue[0].amount;
      this->queue.erase(this->queue.begin());
    } else {
      this->queue[0].amount -= newAmount;
      newAmount = 0;
    }
  }

  return newAmount;
}

vector<Garbage> GarbageQueue::tank(int frame) {
  int amount = this->getCap(frame);

  vector<Garbage> res = {};

  vector<Garbage> tankable;
  for (Garbage garbage : this->queue) {
    if (frame - garbage.frame >= this->options.speed) {
      tankable.push_back(garbage);
    }
  }

  sort(tankable.begin(), tankable.end());

  while (amount > 0 && (int)tankable.size() > 0) {
    if (amount >= (int)this->queue.size()) {
      res.push_back(*this->queue.erase(this->queue.begin()));
      tankable.erase(tankable.begin());
    } else {
      this->queue[0].amount -= amount;
      amount = 0;
    }
  }

  return res;
}