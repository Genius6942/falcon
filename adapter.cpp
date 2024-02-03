#include "adapter.h"

#include "runner/engine.h"

void start_adapter(EngineInitializeParams config) {
  cout << json{{"type", "loading"}} << endl;
  Engine engine = Engine(config);

  cout << json{{"type", "queue"}, {"data", engine.queue.value}} << endl;
  cout << json{{"type", "ready"}} << endl;

  while (true) {
    json input;
    try {
      cin >> input;
    } catch (exception e) {
      cout << json{{"type", "error"}, {"message", e.what()}} << endl;
      continue;
    }
    if (!input.contains("type") || !input.contains("data") ||
        !input["type"].is_string()) {
      cout << json{{"type", "error"}, {"message", "Invalid input"}} << endl;
      continue;
    }

    string type = input["type"];
    json data = input["data"];

    if (type == "press") {
      string key = data["key"];
      if (key == "left") {
        engine.moveLeft();
      } else if (key == "right") {
        engine.moveRight();
      } else if (key == "ccw") {
        engine.rotateCCW();
      } else if (key == "cw") {
        engine.rotateCW();
      } else if (key == "180") {
        engine.rotate180();
      } else if (key == "soft") {
        engine.softDrop();
      } else if (key == "hard") {
        engine.hardDrop();
      } else if (key == "hold") {
        engine.hold();
      } else {
        cout << json{{"type", "error"}, {"message", "Invalid key"}} << endl;
      }
    } else if (type == "garbage") {
      Garbage garbage;
      garbage.amount = data["amount"];
      garbage.column = data["column"];
      garbage.frame = data["frame"];
      garbage.size = data["size"];
      engine.recieveGarbage({garbage});
    } else if (type == "suggest") {
      if (!data.contains("id")) {
        cout << json{{"type", "error"}, {"message", "Missing [id] field"}}
             << endl;
      } else {
        SolveConfig config;
        auto res = solve(&engine, config);
        cout << json{{"type", "suggestion"},
                     {"data",
                      {{"keys", res.solve},
                       {"full", res.future},
                       {"nodes", res.nodes},
                       {"threads", thread::hardware_concurrency()}}}}
             << endl;
      }
    } else {
      cout << json{{"type", "error"}, {"message", "Invalid type"}} << endl;
    }
  }
}