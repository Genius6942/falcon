#include "utils.h"

#include <iostream>

using namespace std;

vector<string> flushableLog = {};

void logInfo(string message) {
  cout << json{{"type", "log"}, {"data", message}} << endl;
}

void flushLog() {
  for (auto &message : flushableLog) {
    cout << message << endl;
  }

  flushableLog.clear();
}

void appendLog(string l) { flushableLog.push_back(l); }