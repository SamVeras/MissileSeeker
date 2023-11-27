#include "ray.h"

void Ray::change_direction(Vetor new_dir) {
  this->direction = new_dir.normalized();
};

void Ray::change_position(Vetor new_pos) {
  this->start += new_pos;
};

Ray::Ray(Vetor pos, Vetor dir)
    : start(pos), direction(dir), current_length(5000) {
  direction.normalize();
  end_point = start + direction * current_length;
};

const Vetor& Ray::get_point() const {
  return this->end_point;
};

const Vetor& Ray::get_start() const {
  return this->start;
};

RayCheck Ray::check_collision(const Meteor& target) const {
  double t;  // o que nós queremos: distância do ponto até a intersecção
  Vetor C = target.get_position();
  Vetor D = this->direction;  // vetor normalizado
  Vetor O = this->start;
  Vetor E = C - O;            // vetor do ponto até o centro do círculo

  double a = E * D;  // projeção do centro do circulo é o produto interno
  double r = target.get_radius();

  double r_squared = pow(r, 2);
  double b_squared = pow(E.get_magnitude(), 2) - pow(a, 2);

  if (pow(r, 2) - b_squared < 0)  // sem intersecção
    return RayCheck{0, {0, 0}, false};

  double f = sqrt(r_squared - b_squared);
  if (pow(E.get_magnitude(), 2) < r_squared)  // dentro do circulo
    t = a + f;
  else
    t = a - f;

  if (t < 0)
    return RayCheck{0, {0, 0}, false};

  return RayCheck{t, D * t, true};
};

bool Ray::update(const Meteor& target) {
  this->direction.normalize();
  RayCheck temp = this->check_collision(target);
  if (temp.result && temp.hit_length < this->current_length) {
    this->current_length = temp.hit_length;
    this->end_point = temp.hit_position;
  }

  this->end_point = this->direction * this->current_length;
  return temp.result;
};

void Ray::draw(SDL_Renderer* render) {
  draw_line(render, this->start, this->end_point);
  draw_line(render, this->start + Vetor{0, 1}, this->end_point + Vetor{0, 1});
  draw_line(render, this->start + Vetor{1, 0}, this->end_point + Vetor{1, 0});
  this->current_length = 5000;
}