#include "bfs.h"

struct Node {
  vector<string> keys;
  int depth;
};

struct EngineState {
  int rotation;
  pair<int, int> location;
};

vector<string> searchBfs(Engine *engine, int depth,
                         vector<pair<int, int>> target) {
  auto pressKey = [&engine](string key) {
    if (key == "left") {
      engine->moveLeft();
    } else if (key == "right") {
      engine->moveRight();
    } else if (key == "ccw") {
      engine->rotateCCW();
    } else if (key == "cw") {
      engine->rotateCW();
    } else if (key == "180") {
      engine->rotate180();
    } else if (key == "soft") {
      engine->softDrop();
    }
  };

  vector<Node> queue;

  EngineState originalState;
  originalState.rotation = engine->falling.getRotation();
  originalState.location = make_pair(engine->falling.location.first,
                                     engine->falling.location.second);

  auto reset = [&engine, &originalState]() {
    engine->falling.setRotation(originalState.rotation);
    engine->falling.location = originalState.location;
  };

  for (string rot : {"", "cw", "ccw", "180"}) {
    if (rot.length() > 0) {
      pressKey(rot);
    }

    vector<pair<int, int>> blocks = engine->falling.getBlocks();

    int left =
        min_element(blocks.begin(), blocks.end(),
                    [](const pair<int, int> &a, const pair<int, int> &b) {
                      return a.first < b.first;
                    })
            ->first +
        engine->falling.location.first;

    int right =
        engine->board.width - 1 -
        (max_element(blocks.begin(), blocks.end(),
                     [](const pair<int, int> &a, const pair<int, int> &b) {
                       return a.first < b.first;
                     })
             ->first +
         engine->falling.location.first);

    for (int i = 0; i < left; i++) {
      if (rot.length() == 0 && i == 0) continue;
      Node node;
      if (rot.length() > 0) {
        node.keys.push_back(rot);
      }

      for (int j = 0; j < i; j++) {
        node.keys.push_back("left");
      }
    }

    for (int i = 1; i < right; i++) {
      Node node;
      if (rot.length() > 0) {
        node.keys.push_back(rot);
      }

      for (int j = 0; j < i; j++) {
        node.keys.push_back("right");
      }
    }

    reset();
  }

  while (queue.size() > 0) {
    Node item = *queue.erase(queue.begin());

    for (int i = 0; i < item.keys.size() - 1; i++) {
      pressKey(item.keys[i]);
    }

    EngineState og;
    og.rotation = engine->falling.getRotation();
    og.location = make_pair(engine->falling.location.first,
                            engine->falling.location.second);

    pressKey(item.keys[item.keys.size() - 1]);

    if (((find(item.keys.begin(), item.keys.end(), "ccw") != item.keys.end() ||
          find(item.keys.begin(), item.keys.end(), "cw") != item.keys.end() ||
          find(item.keys.begin(), item.keys.end(), "180") != item.keys.end()) &&
         engine->falling.getRotation() == og.rotation) ||
        ((find(item.keys.begin(), item.keys.end(), "left") != item.keys.end() ||
          find(item.keys.begin(), item.keys.end(), "right") !=
              item.keys.end()) &&
         engine->falling.location.first == og.location.first &&
         engine->falling.location.second == og.location.second)) {
      reset();
      continue;
    }

    vector<pair<int, int>> blocks = engine->falling.getBlocks();
    // check if all blocks match
    if (std::all_of(blocks.begin(), blocks.end(),
                    [&engine, &target](const Block &block) {
                      auto x = engine->falling.location.first + block.first;
                      auto y = engine->falling.location.second - block.second;
                      return std::any_of(target.begin(), target.end(),
                                         [x, y](const std::pair<int, int> &t) {
                                           return t.first == x && t.second == y;
                                         });
                    })) {
      reset();
      if (item.keys.back() == "soft") {
        item.keys.pop_back();
      }
      return item.keys;
    } else {
      if (item.depth >= depth) {
        reset();
        continue;
      }
      std::string lastKey = item.keys.back();
      for (const auto &key : {"left", "right", "cw", "ccw", "180", "soft"}) {
        if (key == "hard" || (key == "cw" && lastKey == "ccw") ||
            (key == "ccw" && lastKey == "cw") ||
            (key == "right" && lastKey == "left") ||
            (key == "left" && lastKey == "right")) {
          continue;
        }
        Node node;
        node.keys = item.keys;
        node.keys.push_back(key);
        node.depth = item.depth + 1;
        queue.push_back(node);
      }
      reset();
    }
  }

  return vector<string>();
}