#pragma once

#include "garbageCalc.h"
#include "increases.h"
#include "kicks.h"
#include "tetromino.h"
#include "../../lib/nlohmann/json.hpp"

void logInfo(string message);
extern vector<string> flushableLog;
void flushLog();
void appendLog(string l);