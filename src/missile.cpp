#include "missile.h"
#include "functions.h"

void Missile::track_target() {
  Vetor tracking_vector{target_position - position};
  tracking_vector.set_magnitude(max_speed);
  tracking_vector -= velocity;
  tracking_vector.limit(max_force);
  acceleration += tracking_vector;
};

bool Missile::check_explode(std::unique_ptr<Meteor>& objeto) {
  int coisa = objeto->get_radius() + 30;
  if (distance(this->position, objeto->get_position()) < coisa) {
    objeto->mark_for_destroy();
    return true;
  }
  return false;
};

void Missile::update() {
  track_target();
  velocity += acceleration;
  velocity.limit(max_speed);
  position += velocity;
  acceleration = {0.0, 0.0};
};

void Missile::change_target(Vetor new_target_position) {
  target_position = new_target_position;
};

const Vetor& Missile::get_target() const {
  return target_position;
};

void Missile::draw(SDL_Renderer* render) const {
  draw_line(render, position, (position + velocity * -4));
  draw_line(render, position + Vetor{0, 1},
            (position + velocity * -4) + Vetor{0, 1});
  draw_line(render, position + Vetor{1, 0},
            (position + velocity * -4) + Vetor{1, 0});
};

Missile::Missile(Vetor pos, Vetor vel, Vetor acc, double m_spd, double m_frc)
    : Mobile::Mobile(pos, vel, acc), max_speed(m_spd), max_force(m_frc){};