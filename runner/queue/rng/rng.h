#pragma once

#include <map>
#include <string>

#include "rnggen.h"

// rng formulas
#include "bag14.h"
#include "bag7.h"
#include "classic.h"
#include "pairs.h"
#include "totalMayhem.h"

using namespace std;

extern map<string, RngFunction> rngMap;