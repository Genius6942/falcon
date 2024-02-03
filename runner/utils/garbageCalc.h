#pragma once

#include <algorithm>
#include <cmath>
#include <map>
#include <string>
#include <vector>

using namespace std;

extern map<string, double> garbageData;

extern map<string, vector<double>> comboTable;
struct GarbageMultiplier {
  double value;
  double increase;
  double marginTime;
};

struct GarbageCalcData {
  int lines;
  string spin;
  char piece;
  int b2b;
  int combo;
  int enemies;
  bool perfectClear;
  int frame;
};

struct GarbageCalcConfig {
  string spinBonuses;
  string comboTable;
  bool b2bChaining;
  string garbageTargetBonus;
  GarbageMultiplier garbageMultiplier;
  int garbageAttackCap;
  string garbageBlocking;
};

struct GarbageCalcResult {
  double garbage;
  double bonus;
};

GarbageCalcResult garbageCalcV2(GarbageCalcData data, GarbageCalcConfig config);