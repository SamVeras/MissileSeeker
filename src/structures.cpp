#include <cmath>

#include "structures.h"

Point Point::operator+(const Point &other) const {
  return Point{this->x + other.x, this->y + other.y};
}

Point Point::operator-(const Point &other) const {
  return Point{this->x - other.x, this->y - other.y};
}

Point &Point::operator+=(const Point &other) {
  this->x += other.x;
  this->y += other.y;
  return *this;
};

Point &Point::operator-=(const Point &other) {
  this->x -= other.x;
  this->y -= other.y;
  return *this;
};

bool Point::operator!=(const Point &other) const {
  return (this->x != other.x || this->y != other.y);
};

bool Point::operator==(const Point &other) const {
  return (this->x == other.x && this->y == other.y);
};

double Point::get_magnitude() {
  return sqrt(pow((this->x), 2) + pow((this->y), 2));
};

void Point::set_magnitude(double mag) {
  double old_mag = this->get_magnitude();
  this->x *= (mag / old_mag);
  this->y *= (mag / old_mag);
};

void Point::limit(double limit) {
  if (this->get_magnitude() > limit)
    this->set_magnitude(limit);
};