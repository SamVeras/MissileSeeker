#include "entities.h"
#include <SDL2/SDL.h>
#include <iostream>

/* ----------------------------------------------------------------------- */
/*                              Movable class                              */
/* ----------------------------------------------------------------------- */
void movable::update() {
  this->velocity += this->acceleration;
  this->position += velocity;
};

void movable::draw(SDL_Renderer* renderer) {
  SDL_Rect placeholder{(int)this->position.x, (int)this->position.y, 30, 30};
  SDL_RenderDrawRect(renderer, &placeholder);
}

/* -------------------------------------------------------------------------- */
/*                                Missile class                               */
/* -------------------------------------------------------------------------- */
void missile::track(const Point& target_position) {
  Point desired_velocity{target_position - this->position};
  desired_velocity.set_magnitude(this->max_speed);
  Point steer{desired_velocity - this->velocity};
  this->acceleration += steer;
};

void missile::draw(SDL_Renderer* renderer) {
  double head_x = position.x + velocity.x * 5;
  double head_y = position.y + velocity.y * 5;
  SDL_RenderDrawLine(renderer, position.x, position.y, head_x, head_y);

  // int x = this->position.x;
  // int y = this->position.y;
  // int s = 10;
  // SDL_Rect m_rect = {x - s / 2, y - s / 2, s, s};

  // SDL_RenderDrawRect(renderer, &m_rect);
};

/* -------------------------------------------------------------------------- */
/*                                Balloon class                               */
/* -------------------------------------------------------------------------- */

void balloon::draw(SDL_Renderer* renderer) {
  int x = this->position.x;
  int y = this->position.y;
  int s = this->size;
  SDL_Rect balloon_rect = {x - s / 2, y - s / 2, s, s};
  SDL_RenderDrawRect(renderer, &balloon_rect);
}