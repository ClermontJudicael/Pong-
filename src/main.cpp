#include "ball.hpp"
#include "player.hpp"
#include <raylib.h>

int main(int argc, char *argv[]) {
  const int s_width = 1000;
  const int s_height = 600;
  InitWindow(s_width, s_height, "Ping pong");
  SetTargetFPS(60);

  Ball *ball = new Ball{s_width / 2, s_height / 2, 20};
  ball->set_speed(7, 7);

  // initialize with the width and the height of the paddle
  // and also the x and y position
  Player *player = new Player{s_width - 35, s_height / 2 - 60, 25, 120, 7};

  while (WindowShouldClose() == false) {
    BeginDrawing();
    ball->update(s_width, s_height);
    ball->Draw();
    player->Draw();
    player->Move();
    player->border_collision(s_width, s_height);

    ClearBackground(BLACK);
    DrawLine(s_width / 2, 0, s_width / 2, s_height, WHITE);
    DrawRectangle(10, s_height / 2 - 60, 25, 120, WHITE);
    EndDrawing();
  }
  CloseWindow();
  delete ball;
  return 0;
}
