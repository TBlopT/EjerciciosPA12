#include <iostream>
#include <cmath>

class Point2D {
 public:
  Point2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  void Show() const {
    std::cout << "Punto(" << x << ", " << y << ")" << std::endl;
  }

  void Move(double dx, double dy) {
    x += dx;
    y += dy;
  }

  double Distance(const Point2D& other) const {
    double dx = other.x - x;
    double dy = other.y - y;
    return std::sqrt(dx * dx + dy * dy);
  }

  Point2D Middle(const Point2D& other) const {
    double mx = (x + other.x) / 2.0;
    double my = (y + other.y) / 2.0;
    return Point2D(mx, my);
  }

 private:
  double x, y;
};

int main() {
  Point2D p1(3.0, 4.0);
  Point2D p2(7.0, 1.0);

  std::cout << "Punto 1: ";
  p1.Show();
  std::cout << "Punto 2: ";
  p2.Show();

  double dist = p1.Distance(p2);
  std::cout << "Distancia entre los puntos: " << dist << std::endl;

  Point2D middle = p1.Middle(p2);
  std::cout << "Punto medio: ";
  middle.Show();

  p1.Move(2.0, -1.0);
  std::cout << "Punto 1 después de moverlo: ";
  p1.Show();

  return 0;
}
