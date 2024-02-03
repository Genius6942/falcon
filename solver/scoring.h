#include "../runner/engine.h"

struct ScoringConfig {};
struct ScoringData {
  int sent;
  int singles;
  int doubles;
  int triples;
  int quads;
};

double scoreEngine(ScoringConfig &config, ScoringData &data, Engine* engine);