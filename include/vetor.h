#pragma once
#include <iostream>

struct Vetor {
   double x{};
   double y{};

   Vetor operator-(const Vetor& other) const;
   Vetor operator+(const Vetor& other) const;
   Vetor operator*(const double& other) const;
   Vetor operator/(const double& other) const;
   double operator*(const Vetor& other) const;

   Vetor& operator+=(const Vetor& other);
   Vetor& operator-=(const Vetor& other);
   Vetor& operator*=(const double& other);
   Vetor& operator/=(const double& other);

   bool operator!=(const Vetor& other) const;
   bool operator==(const Vetor& other) const;

   double get_magnitude() const;
   void set_magnitude(double mag);
   void limit(double limit);
   void normalize();
   Vetor normalized() const;

   friend std::ostream& operator<<(std::ostream& os, const Vetor& v);
};