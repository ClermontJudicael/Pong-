#include <raylib.h>

int main(int argc, char *argv[]) {
  InitWindow(600, 500, "Ping pong");
  SetTargetFPS(60);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
