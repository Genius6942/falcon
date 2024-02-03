#include "main.h"

int main() {
  json out = {{"type", "init"}, {"version", "0.1.0"}};
  cout << out << endl;

  json config;
  try {
    cin >> config;
    if (config["type"] != "init") {
      throw "must begin with init message. Provided json type: " +
          (string)config["type"];
    }
  } catch (const json::parse_error &e) {
    cerr << "JSON parse error: " << e.what() << endl;
  }

  if (config["type"] != "init") {
    cerr << "Expected init message, got " << config["type"] << endl;
    return 1;
  }

  try {
    EngineInitializeParams engineConfig =
        config["data"].template get<EngineConfig::EngineInitializeParams>();
    start_adapter(engineConfig);
  } catch (const json::type_error &e) {
    cerr << "JSON initial type error: " << e.what() << endl;
  }

  return 0;
}