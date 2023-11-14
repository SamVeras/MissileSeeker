#include "entities.h"
#include "functions.h"
#include <SDL2/SDL.h>
#include <iostream>

/* ------------------------------------------------------------------------ */
/*                              Drawable class                              */
/* ------------------------------------------------------------------------ */
void drawable::update(){};
void drawable::draw(){};
/* ----------------------------------------------------------------------- */
/*                              Movable class                              */
/* ----------------------------------------------------------------------- */
void movable::update() {
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void movable::draw() {
  double cx1{this->position.x - 15}, cx2{this->position.x + 15};
  double cy1{this->position.y - 15}, cy2{this->position.y + 15};
  SDL_RenderDrawLine(this->renderer, cx1, cy1, cx2, cy2);
}

/* -------------------------------------------------------------------------- */
/*                                Missile class                               */
/* -------------------------------------------------------------------------- */
void missile::set(SDL_Renderer *ren, Point pos, Point vel, Point acc,
                  double m_spd, double m_frc, const Point &t_pos) {
  this->renderer = ren;
  this->position = pos;
  this->velocity = vel;
  this->acceleration = acc;
  this->max_speed = m_spd;
  this->max_force = m_frc;
  this->target_position = &t_pos;
};

void missile::track() {
  Point desired_velocity{*target_position - this->position};
  desired_velocity.set_magnitude(this->max_speed);
  desired_velocity -= this->velocity;
  desired_velocity.limit(this->max_force);
  this->acceleration += desired_velocity;
};

void missile::update() {
  this->track();
  if (get_distance(this->position, *target_position) < 25) {
    this->explode();
  };
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void missile::draw() {
  double head_x = position.x + velocity.x * 6;
  double head_y = position.y + velocity.y * 6;
  SDL_RenderDrawLine(this->renderer, position.x, position.y, head_x, head_y);
};

void missile::explode() {
  draw_circle(this->renderer, this->position, 60);
  this->kill_this = true;
}

/* -------------------------------------------------------------------------- */
/*                                Balloon class                               */
/* -------------------------------------------------------------------------- */
void balloon::set(SDL_Renderer *ren, Point pos, Point vel, Point acc) {
  this->renderer = ren;
  this->position = pos;
  this->velocity = vel;
  this->acceleration = acc;
};

void balloon::draw() {
  // int x = this->position.x;
  // int y = this->position.y;
  // int s = this->size;
  // SDL_Rect balloon_rect = {x - s / 2, y - s / 2, s, s};
  // SDL_RenderDrawRect(this->renderer, &balloon_rect);
  draw_circle(this->renderer, this->position, this->size);
}
