#include "player.hpp"

int main(int argc, char *argv[]) {
  const int s_width = 1000;
  const int s_height = 600;

  int player_score = 0;
  int ai_score = 0;

  InitWindow(s_width, s_height, "Ping pong");
  SetTargetFPS(60);

  Ball *ball = new Ball{s_width / 2, s_height / 2, 20};
  ball->set_speed(7, 7);

  Player *player = new Player{s_width - 35, s_height / 2 - 60, 25, 120, 7};
  Cpu_paddle *paddle = new Cpu_paddle{10, s_height / 2 - 60, 25, 120, 7};

  while (WindowShouldClose() == false) {

    BeginDrawing();

    ball->update(s_width, s_height);
    ball->Draw();
    ball->check_collision(*player, s_width, s_height);
    ball->AI_collision(*paddle, s_width, s_height);

    player->Draw();
    player->Move();
    player->border_collision(s_width, s_height);
    paddle->Draw();
    paddle->follow_ball(ball->get_y());
    paddle->border_collision(s_width, s_height);

    // update score
    if (ball->ai_lost()) {
      player_score++;
      ball->reset();
    }
    if (ball->player_lost(s_width)) {
      ai_score++;
      ball->reset();
    }

    ClearBackground(BLACK);
    DrawLine(s_width / 2, 0, s_width / 2, s_height, WHITE);

    // draw score
    DrawText(TextFormat("%i", ai_score), s_width / 4, 10, 40, WHITE);
    DrawText(TextFormat("%i", player_score), s_width - (s_width / 4), 10, 40,
             WHITE);
    EndDrawing();
  }
  CloseWindow();
  delete ball;
  delete player;
  delete paddle;
  return 0;
}
