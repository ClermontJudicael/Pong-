#include <raylib.h>

class Ball {
public:
  Ball(int _x, int _y, float _radius) : x{_x}, y{_y}, radius{_radius} {};
  void Draw() { DrawCircle(x, y, radius, WHITE); }

  void set_speed(int speed_x, int speed_y) {
    this->speed_x = speed_x;
    this->speed_y = speed_y;
  }

  void update(int width, int height) {
    x += speed_x;
    y += speed_y;
    if (x + radius >= width || x - radius <= 0) {
      speed_x *= -1;
    }
    if (y + radius >= height || y - radius <= 0) {
      speed_y *= -1;
    }
  }

private:
  int x, y;
  float radius;
  int speed_x, speed_y;
};
