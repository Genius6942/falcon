#include <string>
#include <map>
#include <ncurses.h>

#pragma once

using namespace std;

extern map<int, string> keyMap;

string getKey(int key);