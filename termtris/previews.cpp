#include "previews.h"

map<char, Preview> previews = {
  {'J', {.width = 3, .height = 2, .preview = {"J  ", "JJJ"}}},
  {'L', {.width = 3, .height = 2, .preview = {"  L", "LLL"}}},
  {'S', {.width = 3, .height = 2, .preview = {" SS", "SS "}}},
  {'Z', {.width = 3, .height = 2, .preview = {"ZZ ", " ZZ"}}},
  {'T', {.width = 3, .height = 2, .preview = {" T ", "TTT"}}},
  {'I', {.width = 4, .height = 1, .preview = {"IIII"}}},
  {'O', {.width = 2, .height = 2, .preview = {"OO", "OO"}}}
};

Preview getPreview(char c) { return previews[c]; }