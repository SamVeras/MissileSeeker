#include "SDL_wrappers.h"

int draw_line(SDL_Renderer* renderer, Vetor A, Vetor B) {
  // imagine (0,0) -> (350, 350)
  // imagine (200, 200) -> (350 + 200, 350 - 200)
  A.y *= -1, B.y *= -1;
  A += global::true_center, B += global::true_center;

  return SDL_RenderDrawLine(renderer, A.x, A.y, B.x, B.y);
};

int draw_point(SDL_Renderer* renderer, Vetor P) {
  P.y *= -1;
  P += global::true_center;
  return SDL_RenderDrawPoint(renderer, P.x, P.y);
};

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

void draw_grid(SDL_Renderer* ren, int step, Vetor offset) {
  if (step <= 0)
    return;
  Vetor half_screen = global::true_center + offset;

  for (double x = 0; x <= half_screen.x; x += step) {
    draw_line(ren, {x, half_screen.y}, {x, -half_screen.y});
    draw_line(ren, {-x, half_screen.y}, {-x, -half_screen.y});
  }

  for (double y = 0; y <= half_screen.y; y += step) {
    draw_line(ren, {half_screen.x, y}, {-half_screen.x, y});
    draw_line(ren, {half_screen.x, -y}, {-half_screen.x, -y});
  }
};

void draw_cartesian_plane(SDL_Renderer* ren, Vetor offset) {
  Vetor half_screen = global::true_center + offset;

  draw_line(ren, {-half_screen.x, 0}, {half_screen.x, 0});
  draw_line(ren, {0, -half_screen.y}, {0, half_screen.y});
};