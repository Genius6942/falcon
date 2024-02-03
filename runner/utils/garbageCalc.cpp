#include "garbageCalc.h"

#include "increases.h"

using namespace std;

map<string, double> garbageData = {
    {"single", 0},          {"double", 1},
    {"triple", 2},          {"quad", 4},
    {"penta", 5},           {"tspinMini", 0},
    {"tspin", 0},           {"tspinMiniSingle", 0},
    {"tspinSingle", 2},     {"tspinMiniDouble", 1},
    {"tspinDouble", 4},     {"tspinTriple", 6},
    {"tspinQuad", 10},      {"tspinPenta", 12},
    {"backtobackBonus", 1}, {"backtobackBonusLog", 0.8},
    {"comboMinifier", 1},   {"comboMinifierLog", 1.25},
    {"comboBonus", 0.25},   {"allClear", 10},
};

map<string, vector<double>> comboTable = {
    {"none", {0}},
    {"classic guideline", {0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5}},
    {"modern guideline", {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4}},
};

double getDecimal(double number) { return number - floor(number); }

GarbageCalcResult garbageCalcV2(GarbageCalcData data,
                                GarbageCalcConfig config) {
  double garbage = 0;
  string spin = data.spin == "none"   ? ""
                : data.spin == "full" ? "normal"
                                      : data.spin;

  switch (data.lines) {
    case 0:
      garbage = spin == "mini"     ? garbageData["tspinMini"]
                : spin == "normal" ? garbageData["tspin"]
                                   : 0;
      break;
    case 1:
      garbage = spin == "mini"     ? garbageData["tspinMiniSingle"]
                : spin == "normal" ? garbageData["tspinSingle"]
                                   : garbageData["single"];
      break;
    case 2:
      garbage = spin == "mini"     ? garbageData["tspinMiniDouble"]
                : spin == "normal" ? garbageData["tspinDouble"]
                                   : garbageData["double"];
      break;
    case 3:
      garbage =
          !spin.empty() ? garbageData["tspinTriple"] : garbageData["triple"];
      break;
    case 4:
      garbage = !spin.empty() ? garbageData["tspinQuad"] : garbageData["quad"];
      break;
    case 5:
      garbage =
          !spin.empty() ? garbageData["tspinPenta"] : garbageData["penta"];
      break;
    default: {
      int t = data.lines - 5;
      garbage = !spin.empty() ? garbageData["tspinPenta"] + 2 * t
                              : garbageData["penta"] + t;
      break;
    }
  }

  if (!spin.empty() && config.spinBonuses == "handheld" &&
      toupper(data.piece) != 'T') {
    garbage /= 2;
  }

  if (data.lines > 0 && data.b2b > 0) {
    if (config.b2bChaining) {
      double b2bGains =
          garbageData["backtobackBonus"] *
          (floor(1 + log1p(data.b2b * garbageData["backtobackBonusLog"])) +
           (data.b2b == 1
                ? 0
                : (1 + (getDecimal(log1p(data.b2b *
                                         garbageData["backtobackBonusLog"])))) /
                      3));
      garbage += b2bGains;
    } else {
      garbage += garbageData["backtobackBonus"];
    }
  }

  if (data.combo > 0) {
    if (config.comboTable == "multiplier") {
      garbage *= 1 + garbageData["comboBonus"] * data.combo;
      if (data.combo > 1) {
        garbage = max(log1p(garbageData["comboMinifier"] * data.combo *
                            garbageData["comboMinifierLog"]),
                      garbage);
      }
    } else {
      vector<double> comboTableData = comboTable[config.comboTable].empty()
                                          ? vector<double>{0}
                                          : comboTable[config.comboTable];
      garbage += comboTableData[max(
          0, min(data.combo - 1, (int)comboTableData.size() - 1))];
    }
  }

  double garbageMultiplierValue = calculateIncrease(
      config.garbageMultiplier.value, data.frame,
      config.garbageMultiplier.increase, config.garbageMultiplier.marginTime);

  double garbageBonus = 0;
  if (data.lines > 0 && config.garbageTargetBonus != "none") {
    double targetBonus = 0;
    switch (data.enemies) {
      case 0:
      case 1:
        break;
      case 2:
        targetBonus += 1;
        break;
      case 3:
        targetBonus += 3;
        break;
      case 4:
        targetBonus += 5;
        break;
      case 5:
        targetBonus += 7;
        break;
      default:
        targetBonus += 9;
    }

    if (config.garbageTargetBonus == "normal") {
      garbage += targetBonus;
    } else {
      garbageBonus = floor(targetBonus * garbageMultiplierValue);
    }
  }

  double l = floor(garbage * garbageMultiplierValue);
  if (config.garbageAttackCap) {
    l = floor(min((double)config.garbageAttackCap, l));
  }

  // switch (garbageBlocking) {}

  return {l + (data.perfectClear ? 10 * garbageMultiplierValue : 0),
          garbageBonus * garbageMultiplierValue};
}