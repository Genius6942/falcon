#include <ncurses.h>

#include <cmath>
#include <csignal>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <string>
#include <thread>

#include "../lib/nlohmann/json.hpp"
#include "../runner/engine.h"
#include "../runner/utils/utils.h"
#include "controls.h"
#include "previews.h"

using namespace std;
using json = nlohmann::json;

struct Settings {
  bool center = false;
};

Engine engine;

map<char, string> colorMapAnsi = {{'J', "\033["},     {'S', "\033[102m"},
                                  {'Z', "\033[101m"}, {'O', "\033[43m"},
                                  {'L', "\033[41m"},  {'I', "\033[104m"},
                                  {'T', "\033[105m"}, {'X', "\033[0m"}};
map<char, string> colorMap = {{'J', "1"}, {'S', "2"}, {'Z', "3"}, {'O', "4"},
                              {'L', "5"}, {'I', "6"}, {'T', "7"}, {'H', "8"}};
string color(string str, char color) {
  string res = "{" + colorMap[color] + str + "}";
  return res;
}

vector<string> getBoardString(vector<vector<char>> b) {
  vector<string> board;

  for (auto row : b) {
    string res = "";

    for (char s : row) {
      if (s == 'X')
        res += "  ";
      else
        res += color("  ", s);
    }

    board.push_back(res);
  }

  return board;
}

void renderEngine(Engine *engine, bool centerBoard) {
  // create board data (including falling piece)
  auto boardState = engine->board.state;

  const int currentLocation = engine->falling.location.second;
  engine->softDrop();
  const auto shadowBlocks = engine->falling.getAbsoluteBlocks();
  engine->falling.location.second = currentLocation;

  for (auto &block : shadowBlocks) {
    boardState[block.second][block.first] = 'H';
  }

  for (auto &block : engine->falling.getAbsoluteBlocks()) {
    boardState[block.second][block.first] = engine->falling.symbol;
  }

  auto board = getBoardString(boardState);

  vector<string> result;

  const int previewWidth = 10;
  const int previewHeight = 2;
  const int visibleBuffer = 4;

  // buffer section at top
  for (int i = 0; i < visibleBuffer; i++) {
    result.push_back(string(previewWidth + 1, ' ') + "|");
  }

  // render top of hold
  result.push_back("+" + string(previewWidth, '-') + "|");

  // create hold stuffs
  Preview hold;
  if (engine->held.has_value()) {
    hold = getPreview(engine->held.value());
  } else {
    hold = {.width = 0, .height = 0, .preview = {}};
  }
  const int holdMargin = (previewWidth - hold.width * 2) / 2;
  vector<string> holdPreview;
  for (int i = 0; i < hold.height; i++) {
    string s = "";
    for (auto c : hold.preview[i]) {
      if (c == ' ')
        s += "  ";
      else
        s += color("  ", c);
    }
    holdPreview.push_back(s);
  }

  // extra part of hold if its short (i piece)
  for (int i = 0; i < previewHeight - hold.height; i++)
    holdPreview.push_back(string(hold.width * 2, ' '));

  // render hold
  for (auto s : holdPreview) {
    result.push_back("|" + string(holdMargin, ' ') + s +
                     string(holdMargin, ' ') + "|");
  }

  // render bottom of hold
  result.push_back("+" + string(previewWidth, '-') + "|");

  // render left side of board below hold
  for (int i = 0; i < engine->board.height - 2 - previewHeight; i++) {
    result.push_back(string(previewWidth + 1, ' ') + "|");
  }

  // render bottom of board
  result.push_back(string(previewWidth + 1, ' ') + "+" +
                   string(engine->board.width * 2, '-') + "+");

  // render board
  for (int i = engine->board.height - 1 + visibleBuffer; i >= 0; i--) {
    result[engine->board.height - 1 + visibleBuffer - i] += board[i] + "|";
  }

  // render top of queue
  result[visibleBuffer] += string(previewWidth, '-') + "+";
  result[visibleBuffer + 1] += string(previewWidth, ' ') + "|";

  // render queue
  int queueIndex = 2 + visibleBuffer;
  const int queueLength = 5;
  const int queueHeight = 6 + 5 * 2;

  for (int i = 0; i < queueLength; i++) {
    auto preview = getPreview(engine->queue.value[i]);

    const int margin = (previewWidth - preview.width * 2) / 2;

    for (auto row : preview.preview) {
      string s = "";
      for (auto c : row) {
        if (c == ' ')
          s += "  ";
        else
          s += color("  ", c);
      }
      result[queueIndex] += string(margin, ' ') + s + string(margin, ' ') + '|';
      queueIndex++;
    }

    result[queueIndex] += string(previewWidth, ' ') + "|";

    queueIndex++;
  }

  // render leftover queue space
  for (int i = 0; i < queueHeight + 1 - queueIndex + visibleBuffer; i++) {
    result[queueIndex] += string(previewWidth, ' ') + "|";
    queueIndex++;
  }

  // render bottom of queue
  result[queueIndex] += string(previewWidth, '-') + "+";

  const int boardWidth =
      1 + previewWidth + 1 + engine->board.width * 2 + 1 + previewWidth + 1;
  const int boardMargin = (COLS - boardWidth) / 2;
  // ----- render -----
  for (auto line : result) {
    // center board
    if (centerBoard) printw("%*s", boardMargin, "");

    int color = 0;
    for (auto c : line) {
      if (c == '{') {
        color = -1;
      } else if (c == '}') {
        attroff(COLOR_PAIR(color));
        color = 0;
      } else if (color == -1) {
        color = c - '0';
        attron(COLOR_PAIR(color));
      } else {
        addch(c);
      }
    }
    addch('\n');
  }

  addch('\n');

  string statsText = "B2B: " + to_string(max(engine->stats.b2b, 0)) +
                     ", Combo: " + to_string(max(engine->stats.combo, 0));
  int statsTextMargin = max((COLS - (int)statsText.length()) / 2, 0);
  printw("%*s", statsTextMargin, "");
  printw(statsText.c_str());
  addch('\n');

  printw("(Esc to exit)\n");
}

vector<string> logs;

int main() {
  // block keyboardinterupt
  // Create a new process group
  setpgid(0, 0);

  // Ignore the SIGTSTP signal (this is what's sent when you press Ctrl+Z)
  signal(SIGINT, SIG_IGN);

  // seed random (For random results)
  srand(time(NULL));

  json engineConfigJson = json::parse(
      R"({"board":{"width":10,"height":20,"buffer":20},"garbage":{"cap":{"absolute":1000,"increase":0,"max":1000,"value":8},"speed":20},"kickTable":"SRS+","options":{"b2bChaining":true,"comboTable":"multiplier","garbageBlocking":"combo blocking","garbageMultiplier":{"increase":0,"marginTime":0,"value":1},"garbageTargetBonus":"none","spinBonuses":"t-spins","garbageAttackCap":10000},"queue":{"minLength":20,"seed":0,"type":"7-bag"}})");

  engineConfigJson["queue"]["seed"] = floor(rand());

  auto engine = Engine(
      engineConfigJson.template get<EngineConfig::EngineInitializeParams>());

  // curses stuff
  // Initialize the library
  initscr();
  // color stuff
  start_color();
  // J
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  // S
  init_pair(2, COLOR_BLACK, COLOR_GREEN);
  // Z
  init_pair(3, COLOR_BLACK, COLOR_RED);
  // O
  init_pair(4, COLOR_BLACK, COLOR_YELLOW + 8);
  // L
  init_pair(5, COLOR_WHITE, COLOR_YELLOW);
  // I
  init_pair(6, COLOR_WHITE, COLOR_BLUE + 8);
  // T
  init_pair(7, COLOR_WHITE, COLOR_MAGENTA);
  // shadow
  init_pair(8, COLOR_BLACK, COLOR_WHITE);
  // default
  init_pair(9, COLOR_WHITE, COLOR_BLACK);

  // Enable special key input, like function keys
  keypad(stdscr, TRUE);
  // Don't display input characters on the scr
  noecho();
  // Hide the cursor
  curs_set(FALSE);

  bool running = true;
  string scr = "menu";

  auto pressKey = [&engine, &running, &engineConfigJson, &scr](string key) {
    if (key == "left")
      engine.moveLeft();
    else if (key == "right")
      engine.moveRight();
    else if (key == "ccw")
      engine.rotateCCW();
    else if (key == "cw")
      engine.rotateCW();
    else if (key == "180")
      engine.rotate180();
    else if (key == "soft")
      engine.softDrop();
    else if (key == "hard") {
      engine.checkpoint();
      engine.hardDrop();
    } else if (key == "hold")
      engine.hold();
    else if (key == "undo") {
      engine.revert();
    } else if (key == "quit")
      scr = "menu";
    else if (key == "reset") {
      engineConfigJson["queue"]["seed"] = floor(rand());

      engine =
          Engine(engineConfigJson
                     .template get<EngineConfig::EngineInitializeParams>());
    }
  };

  // signal(SIGTSTP, handle_ctrlz);

  Settings settings;
  settings.center = true;
  vector<string> menuOptions = {"Play", "Settings", "Quit"};
  int menuIndex = 0;

  thread renderThread(
      [&engine, &running, &settings, &scr, &menuOptions, &menuIndex]() {
        while (running) {
          clear();
          if (scr == "game") {
            renderEngine(&engine, settings.center);
          } else if (scr == "menu") {
            printw("Welcome to Termtris!\n");
            for (int i = 0; i < menuOptions.size(); i++) {
              if (i == menuIndex) {
                printw(" > ");
              } else {
                printw("   ");
              }
              printw(menuOptions[i].c_str());
              printw("\n");
            }
          } else if (scr == "settings") {
            printw("Settings\n");
            // printw("Center board: ");
            // if (settings.center) {
            // 	printw("On\n");
            // } else {
            // 	printw("Off\n");
            // }
            printw("Coming soon...\n");
            printw("Press 'esc' to go back\n");
          }
          refresh();
          this_thread::sleep_for(chrono::milliseconds(1000 / 60));
        }
      });

  while (running) {
    auto c = getch();

    auto key = getKey(c);

    if (key.length() > 0) {
      if (scr == "game") {
        pressKey(key);
      } else if (scr == "menu") {
        if (key == "cw") {
          menuIndex--;
          if (menuIndex < 0) menuIndex = menuOptions.size() - 1;
        } else if (key == "soft") {
          menuIndex++;
          if (menuIndex >= menuOptions.size()) menuIndex = 0;
        } else if (key == "enter" || key == "hard") {
          if (menuOptions[menuIndex] == "Play") {
            scr = "game";
          } else if (menuOptions[menuIndex] == "Settings") {
            scr = "settings";
          } else if (menuOptions[menuIndex] == "Quit") {
            running = false;
            break;
          }
        }
      } else if (scr == "settings") {
        if (key == "quit") {
          scr = "menu";
        }
      }
    }
  }

  clear();
  refresh();
  endwin();
  renderThread.detach();

  std::cout << "Thanks for playing!" << endl;
  flushLog();

  return 0;
}