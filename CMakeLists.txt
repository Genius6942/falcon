cmake_minimum_required(VERSION 3.10)
project(falcon)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -Wno-unused-result -Wno-format-security")


# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})



# add_executable(falcon main.cpp main.h adapter.cpp adapter.h ./runner/garbage.cpp ./runner/board.cpp ./runner/board.h ./runner/utils/tetromino.h ./runner/utils/kickData.h ./runner/utils/kicks.h ./runner/utils/increases.cpp ./runner/utils/tetrominoData.cpp ./runner/utils/tetromino.cpp ./runner/utils/garbageCalc.cpp ./runner/utils/garbageCalc.h ./runner/utils/tetrominoData.h ./runner/utils/utils.h ./runner/utils/increases.h ./runner/utils/kicks.cpp ./runner/utils/kickData.cpp ./runner/garbage.h ./runner/engine.cpp ./runner/queue/queue.h ./runner/queue/queue.cpp ./runner/queue/rng/bag14.cpp ./runner/queue/rng/pairs.cpp ./runner/queue/rng/totalMayhem.cpp ./runner/queue/rng/bag14.h ./runner/queue/rng/classic.h ./runner/queue/rng/pairs.h ./runner/queue/rng/bag7.h ./runner/queue/rng/bag7.cpp ./runner/queue/rng/classic.cpp ./runner/queue/rng/rng.cpp ./runner/queue/rng/totalMayhem.h ./runner/queue/rng/rnggen.h ./runner/queue/rng/rng.h ./runner/search/search.h ./runner/search/bfs.h ./runner/search/bfs.cpp ./runner/engine.h ./solver/solver.h ./solver/solver.cpp ./solver/keycalc.h ./solver/keycalc.cpp ./solver/scoring.h ./solver/scoring.cpp ./runner/utils/utils.cpp)

add_executable(termtris ./termtris/main.cpp ./termtris/previews.h ./termtris/previews.cpp ./termtris/controls.h ./termtris/controls.cpp ./runner/garbage.cpp ./runner/board.cpp ./runner/board.h ./runner/utils/tetromino.h ./runner/utils/kickData.h ./runner/utils/kicks.h ./runner/utils/increases.cpp ./runner/utils/tetrominoData.cpp ./runner/utils/tetromino.cpp ./runner/utils/garbageCalc.cpp ./runner/utils/garbageCalc.h ./runner/utils/tetrominoData.h ./runner/utils/utils.h ./runner/utils/utils.cpp ./runner/utils/increases.h ./runner/utils/kicks.cpp ./runner/utils/kickData.cpp ./runner/garbage.h ./runner/engine.cpp ./runner/queue/queue.h ./runner/queue/queue.cpp ./runner/queue/rng/bag14.cpp ./runner/queue/rng/pairs.cpp ./runner/queue/rng/totalMayhem.cpp ./runner/queue/rng/bag14.h ./runner/queue/rng/classic.h ./runner/queue/rng/pairs.h ./runner/queue/rng/bag7.h ./runner/queue/rng/bag7.cpp ./runner/queue/rng/classic.cpp ./runner/queue/rng/rng.cpp ./runner/queue/rng/totalMayhem.h ./runner/queue/rng/rnggen.h ./runner/queue/rng/rng.h ./runner/search/search.h ./runner/search/bfs.h ./runner/search/bfs.cpp ./runner/engine.h)
target_link_libraries(termtris ${CURSES_LIBRARIES})