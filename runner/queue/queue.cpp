#include "queue.h"
#include "../utils/utils.h"

Queue::Queue(QueueInitializeParams options) {
  this->seed = options.seed;
  this->type = options.type;
  this->minLength = options.minLength;
  this->value = {};
  this->reset(0);
}

void Queue::reset(int idx) {
  this->genFunction = rngMap[this->type](this->seed);
  this->value = {};
  this->index = idx;

  this->repopulate();
  for (int i = 0; i < idx; i++) {
		// can't use .shift() because it increments queue and does other things we don't need
    this->value.erase(this->value.begin());
    this->repopulate();
  }
}

void Queue::onRepopulate(void (*listener)(vector<char> pieces)) {
  this->repopulateListener = listener;
}

char Queue::next() { return this->value[0]; }

char Queue::at(int idx) { return this->value[idx]; }

char Queue::shift() {
  char piece = this->value[0];
  this->value.erase(this->value.begin());
  this->repopulate();
	this->index++;
  return piece;
}

vector<string> Queue::as_string() {
  vector<string> result = {};
  for (char piece : this->value) {
    result.push_back(string(1, piece));
  }
  return result;
}

void Queue::repopulate() {
  vector<char> added = {};
  while (this->value.size() < this->minLength) {
    vector<char> newPieces = this->genFunction();
    for (char piece : newPieces) {
      added.push_back(piece);
      this->value.push_back(piece);
    }
  }

  this->repopulateListener(added);
}