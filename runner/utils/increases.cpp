#include "increases.h"

double calculateIncrease(double base, int frames, double increase,
                         double marginTime) {
  int times = floor(max(0.0, frames - marginTime) / 60);
  return base + increase * times;
}