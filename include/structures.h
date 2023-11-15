#pragma once

struct Point {
  double x{};
  double y{};

  Point operator-(const Point& other) const;
  Point operator+(const Point& other) const;

  Point& operator+=(const Point& other);
  Point& operator-=(const Point& other);

  bool operator!=(const Point& other) const;
  bool operator==(const Point& other) const;

  double get_magnitude();
  void set_magnitude(double mag);
  void limit(double limit);
};

struct Line {
  Point p1;
  Point p2;
};