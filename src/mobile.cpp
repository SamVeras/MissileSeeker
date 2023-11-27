#include "mobile.h"

void Mobile::update() {
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void Mobile::mark_for_destroy() {
  this->destroy = true;
};

void Mobile::mark_out_of_bounds() {
  this->out_of_bounds = true;
};

const bool& Mobile::check_destroy() const {
  return this->destroy;
};

const bool& Mobile::check_bounds() const {
  return this->out_of_bounds;
};

const Vetor& Mobile::get_position() const {
  return this->position;
};

void Mobile::change_position(Vetor new_pos) {
  this->position = new_pos;
};

void Mobile::draw(SDL_Renderer* render) const {
  draw_point(render, this->position);
};

Mobile::Mobile(Vetor pos, Vetor vel, Vetor acc)
    : position(pos), velocity(vel), acceleration(acc), destroy(false){};