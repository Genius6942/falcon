#include "rng.h"

map<string, RngFunction> rngMap = {{"7-bag", bag7},
                                   {"14-bag", bag14},
                                   {"classic", classic},
                                   {"pairs", pairs},
                                   {"total-mayhem", totalMayhem}};