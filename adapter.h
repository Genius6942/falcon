// adapter.h
#pragma once

#include <iostream>
#include <thread>

#include "lib/nlohmann/json.hpp"
#include "runner/engine.h"
#include "solver/solver.h"

using namespace std;

using json = nlohmann::json;

void start_adapter(EngineInitializeParams config);