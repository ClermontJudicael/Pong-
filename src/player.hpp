#pragma once

#include <raylib.h>
#include <unistd.h>

class Player {
public:
  Player(int x, int y, float width, float height, int speed)
      : x{x}, y{y}, width{width}, height{height}, speed{speed} {}

  void Draw() { DrawRectangle(x, y, width, height, WHITE); }

  void Move();

  void border_collision(float s_width, float s_height);

  float get_width() const { return width; }

  float get_heigth() const { return height; }

  int get_x() const { return x; }

  int get_y() const { return y; }

protected:
  int x, y;
  float width, height;
  int speed;
};

class Cpu_paddle : public Player {
public:
  Cpu_paddle(int x, int y, float width, float height, int speed)
      : Player(x, y, width, height, speed) {}

  void follow_ball(int ball_y) {
    if (ball_y < y) {
      y -= speed;
    } else {
      y += speed;
    }
  }
};

class Ball {
public:
  Ball(int _x, int _y, float _radius) : x{_x}, y{_y}, radius{_radius} {};
  void Draw() { DrawCircle(x, y, radius, WHITE); }

  void set_speed(int speed_x, int speed_y);

  void update(int width, int height);

  bool ai_lost();

  bool player_lost(int s_width);

  void check_collision(Player &p, int s_width, int s_height);

  void AI_collision(Cpu_paddle &ai, int s_width, int s_height);

  void reset() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    sleep(1);
  }

  int get_x() const { return x; }
  int get_y() const { return y; }
  float get_radius() const { return radius; }

private:
  int x, y;
  float radius;
  int speed_x, speed_y;
};
