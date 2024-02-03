#include <map>
#include <vector>
#include <string>

using namespace std;
#pragma once

struct Preview {
  int width;
  int height;
  vector<string>preview;
};

extern map<char, Preview> previews;

Preview getPreview(char c);