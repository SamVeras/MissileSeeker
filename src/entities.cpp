#include <SDL2/SDL.h>
#include <iostream>

#include "entities.h"
#include "functions.h"
/* ----------------------------------------------------------------------- */
/*                              Movable class                              */
/* ----------------------------------------------------------------------- */
void movable::update() {
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void movable::draw() {
  SDL_Rect placeholder{(int)this->position.x, (int)this->position.y, 30, 30};
  SDL_RenderDrawRect(this->renderer, &placeholder);
}

/* -------------------------------------------------------------------------- */
/*                                Missile class                               */
/* -------------------------------------------------------------------------- */
void missile::track() {
  Point desired_velocity{*target_position - this->position};
  desired_velocity.set_magnitude(this->max_speed);
  desired_velocity -= this->velocity;
  desired_velocity.limit(this->max_force);
  this->acceleration += desired_velocity;
};

void missile::update() {
  this->track();
  if (get_distance(this->position, *target_position) < 10) {
    this->explode();
  };
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void missile::draw() {
  double head_x = position.x + velocity.x * 2;
  double head_y = position.y + velocity.y * 2;
  SDL_RenderDrawLine(this->renderer, position.x, position.y, head_x, head_y);
};

void missile::explode() {
  draw_circle(this->renderer, this->position, 20);
  draw_circle(this->renderer, this->position, 30);
  draw_circle(this->renderer, this->position, 40);
}

/* -------------------------------------------------------------------------- */
/*                                Balloon class                               */
/* -------------------------------------------------------------------------- */

void balloon::draw() {
  int x = this->position.x;
  int y = this->position.y;
  int s = this->size;
  SDL_Rect balloon_rect = {x - s / 2, y - s / 2, s, s};
  SDL_RenderDrawRect(this->renderer, &balloon_rect);
}
