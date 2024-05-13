#include "ball.hpp"
#include <raylib.h>

int main(int argc, char *argv[]) {
  const int width = 1000;
  const int height = 600;
  InitWindow(width, height, "Ping pong");
  SetTargetFPS(60);

  Ball *ball = new Ball{width / 2, height / 2, 20};
  ball->set_speed(7, 7);

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball->update(width, height);
    ball->Draw();

    ClearBackground(BLACK);
    DrawLine(width / 2, 0, width / 2, height, WHITE);

    EndDrawing();
  }
  CloseWindow();
  delete ball;
  return 0;
}
