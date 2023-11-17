#include <cmath>

#include "SDL_wrappers.h"
#include "functions.h"

void draw_circle(SDL_Renderer* ren, Vetor center, double radius) {
   Vetor coord = {0, radius};
   int decision = 3 - 2 * radius;

   while (coord.x <= coord.y) {
      int x = coord.x;
      int y = coord.y;

      Vetor octant1 = {center.x + x, center.y + y};
      Vetor octant2 = {center.x - x, center.y + y};
      Vetor octant3 = {center.x - y, center.y + x};
      Vetor octant4 = {center.x + y, center.y + x};

      Vetor octant5 = {center.x + x, center.y - y};
      Vetor octant6 = {center.x - x, center.y - y};
      Vetor octant7 = {center.x - y, center.y - x};
      Vetor octant8 = {center.x + y, center.y - x};

      draw_point(ren, octant1);
      draw_point(ren, octant2);
      draw_point(ren, octant3);
      draw_point(ren, octant4);

      draw_point(ren, octant5);
      draw_point(ren, octant6);
      draw_point(ren, octant7);
      draw_point(ren, octant8);

      if (decision < 0) {
         coord += Vetor{1, 0};
         decision += 4 * coord.x + 6;
      } else {
         coord += Vetor{1, -1};
         decision += 4 * (coord.x - coord.y) + 10;
      };
   };
};

void draw_filled_circle(SDL_Renderer* ren, Vetor center, double radius) {
   Vetor coord = {0, radius};
   int decision = 3 - 2 * radius;

   while (coord.x <= coord.y) {
      int x = coord.x;
      int y = coord.y;

      Vetor octant1 = {center.x + x, center.y + y};
      Vetor octant2 = {center.x - x, center.y + y};
      Vetor octant3 = {center.x - y, center.y + x};
      Vetor octant4 = {center.x + y, center.y + x};

      Vetor octant5 = {center.x + x, center.y - y};
      Vetor octant6 = {center.x - x, center.y - y};
      Vetor octant7 = {center.x - y, center.y - x};
      Vetor octant8 = {center.x + y, center.y - x};

      draw_line(ren, octant1, octant5);
      draw_line(ren, octant2, octant6);
      draw_line(ren, octant3, octant7);
      draw_line(ren, octant4, octant8);

      if (decision < 0) {
         coord += Vetor{1, 0};
         decision += 4 * coord.x + 6;
      } else {
         coord += Vetor{1, -1};
         decision += 4 * (coord.x - coord.y) + 10;
      };
   };
};

double distance(Vetor p1, Vetor p2) {
   return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
};

double to_radians(double degrees) {
   return degrees * (M_PI / 180);
};

double to_degrees(double radians) {
   return radians * (180 / M_PI);
};