#include "player.hpp"

void Player::Move() {
  if (IsKeyDown(KEY_UP)) {
    y -= speed;
  } else if (IsKeyDown(KEY_DOWN)) {
    y += speed;
  }
}

void Player::border_collision(float s_width, float s_height) {
  if (y <= 0) {
    y = 0;
  } else if (y + height >= s_height) {
    y = s_height - height;
  }
}

void Ball::set_speed(int speed_x, int speed_y) {
  this->speed_x = speed_x;
  this->speed_y = speed_y;
}

void Ball::update(int width, int height) {
  x += speed_x;
  y += speed_y;

  if (y + radius >= height || y - radius <= 0) {
    speed_y *= -1;
  }
}

bool Ball::ai_lost() { return x - radius <= 0 ? true : false; }

bool Ball::player_lost(int s_width) {
  return (x + radius >= s_width) ? true : false;
}

void Ball::check_collision(Player &p, int s_width, int s_height) {
  if(x+radius >= s_width -p.get_width() &&
      (y >=p.get_y() && p.get_y()+p.get_heigth())) {
    speed_x *= -1;
  }
}

void Ball::AI_collision(Cpu_paddle &ai, int s_width, int s_height) {
  if (x - radius <= ai.get_x() + ai.get_width()
      && (y>= ai.get_y() && y <= ai.get_y() + ai.get_heigth())){
    speed_x *= -1;
  }
}
