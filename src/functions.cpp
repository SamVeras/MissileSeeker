#include <cmath>

#include "functions.h"

double distance(Vetor p1, Vetor p2) {
  return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};

double to_radians(double degrees) {
  return degrees * (M_PI / 180);
};

double to_degrees(double radians) {
  return radians * (180 / M_PI);
};

int biased_randint(int min, int max) {
  if (min > max)
    return 0;
  int r = 0;
  // do {
  r = min + (std::rand() % (max - min + 1));
  // } while (r < min || r > max);
  return r;
};