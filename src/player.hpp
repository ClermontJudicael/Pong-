#include <raylib.h>

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
  int get_x() const { return x; }
  int get_y() const { return y; }

private:
  int x, y;
  float width, height;
  int speed;
};

class Cpu_paddle : public Player {
public:
  // Appeler le constructeur de la classe mère
  Cpu_paddle(int x, int y, float width, float height, int speed)
      : Player(x, y, width, height, speed) {}
};

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

  void check_collision(Player &p, int s_width, int s_height) {
    if (x + radius >= s_width - p.get_width() &&
        (y >= p.get_y() && y <= p.get_y() + p.get_heigth())) {
      speed_x *= -1;
    }
  }

  void AI_collision(Cpu_paddle &ai, int s_width, int s_height) {
    if (x - radius <= ai.get_x() + ai.get_width() &&
        (y >= ai.get_y() && y <= ai.get_y() + ai.get_heigth())) {
      speed_x *= -1;
    }
  }

  int get_x() const { return x; }
  int get_y() const { return y; }
  float get_radius() const { return radius; }

private:
  int x, y;
  float radius;
  int speed_x, speed_y;
};
