#include "controls.h"

map<int, string> keyMap = {
    {KEY_UP, "cw"},       {KEY_DOWN, "soft"}, {KEY_LEFT, "left"},
    {KEY_RIGHT, "right"}, {32, "hard"},       {27, "quit"},
    {122, "ccw"},         {97, "180"},        {'r', "reset"},
    {'c', "hold"},        {'\n', "enter"},    {'\r', "enter"}};

string getKey(int key) {
  if (keyMap.find(key) != keyMap.end()) {
    return keyMap[key];
  }
  return "";
}