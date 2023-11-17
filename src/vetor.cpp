#include "vetor.h"
#include <cmath>

Vetor Vetor::operator+(const Vetor& other) const {
   return Vetor{this->x + other.x, this->y + other.y};
}

Vetor Vetor::operator-(const Vetor& other) const {
   return Vetor{this->x - other.x, this->y - other.y};
}

Vetor Vetor::operator*(const double& other) const {
   return Vetor{this->x * other, this->y * other};
};

Vetor Vetor::operator/(const double& other) const {
   return Vetor{this->x / other, this->y / other};
};

double Vetor::operator*(const Vetor& other) const {
   return (this->x * other.x) + (this->y * other.y);
};  // produto interno

Vetor& Vetor::operator+=(const Vetor& other) {
   return *this = *this + other;
};

Vetor& Vetor::operator-=(const Vetor& other) {
   return *this = *this - other;
};

Vetor& Vetor::operator*=(const double& other) {
   return *this = *this * other;
};

Vetor& Vetor::operator/=(const double& other) {
   return *this = *this / other;
};

bool Vetor::operator!=(const Vetor& other) const {
   return (this->x != other.x || this->y != other.y);
};

bool Vetor::operator==(const Vetor& other) const {
   return (this->x == other.x && this->y == other.y);
};

double Vetor::get_magnitude() const {
   return sqrt(pow((this->x), 2) + pow((this->y), 2));
};

void Vetor::set_magnitude(double mag) {
   *this *= (mag / this->get_magnitude());
};

void Vetor::normalize() {
   double mag = this->get_magnitude();
   if (mag == 0)
      return;
   *this /= mag;
};

Vetor Vetor::normalized() const {
   return *this / this->get_magnitude();
};

void Vetor::limit(double limit) {
   if (this->get_magnitude() > limit)
      this->set_magnitude(limit);
};

std::ostream& operator<<(std::ostream& os, const Vetor& v) {
   os << "(" << v.x << ", " << v.y << ")";
   return os;
};
