clang++ ./src/main.cpp ./src/player.cpp -o main `pkg-config --libs --cflags raylib`
./main
