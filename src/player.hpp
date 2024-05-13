#include "raylib.h"

class Player {
public:
  Player(int x, int y, float width, float height, int speed)
      : x{x}, y{y}, width{width}, height{height}, speed{speed} {}
  void Draw() { DrawRectangle(x, y, width, height, WHITE); }
  void Move() {
    if (IsKeyDown(KEY_UP)) {
      y -= speed;
    } else if (IsKeyDown(KEY_DOWN)) {
      y += speed;
    }
  }
  void border_collision(float s_width, float s_height) {
    if (y <= 0) {
      y = 0;
    } else if (y + height >= s_height) {
      y = s_height - height;
    }
  }

  float get_width() const { return width; }
  float get_heigth() const { return height; }

private:
  int x, y;
  float width, height;
  int speed;
};
