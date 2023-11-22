#include "missile.h"

void Missile::track_target() {
  Vetor tracking_vector{target_position - this->position};
  tracking_vector.set_magnitude(this->max_speed);
  tracking_vector -= this->velocity;
  tracking_vector.limit(this->max_force);
  this->acceleration += tracking_vector;
};

void Missile::update() {
  this->track_target();
  this->velocity += this->acceleration;
  this->velocity.limit(max_speed);
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
};

void Missile::change_target(Vetor new_target_position) {
  this->target_position = new_target_position;
};

const Vetor& Missile::get_target() const {
  return this->target_position;
};

void Missile::draw(SDL_Renderer* render) const {
  draw_line(render, this->position, (this->position + this->velocity * -4));
  draw_line(render, this->position + Vetor{0, 1},
            (this->position + this->velocity * -4) + Vetor{0, 1});
  draw_line(render, this->position + Vetor{1, 0},
            (this->position + this->velocity * -4) + Vetor{1, 0});
};

Missile::Missile(Vetor pos, Vetor vel, Vetor acc, double m_spd, double m_frc)
    : Mobile::Mobile(pos, vel, acc), max_speed(m_spd), max_force(m_frc){};