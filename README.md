# Falcon
### not very fast but it will be
#### also it doesnt work

------------

Requirements: cmake + some c++ compiler

## Building

Run:
```bash
mkdir build # if no build folder already
cd build
cmake ..
cmake --build .
```

## Using/Running

Run the executable (see "Building")
```bash
build/falcon
```

The system uses json for interaction handling, sent through stdin/stdout

#### Events
Recieve: `{"type": "init", "version": STRING}`

Send: big json (docs coming later)

Recieve: `{"type": "loading"}`

Recieve: `{"type": "queue", "data": STRING[]}`

Recieve: `{"type": "ready"}`

now you can do stuff after this

good luck