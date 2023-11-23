#include "meteor.h"
#include <algorithm>

Meteor::Meteor(Vetor pos, Vetor vel, Vetor acc, double r)
    : Mobile::Mobile(pos, vel, acc), radius(r){};

const double& Meteor::get_radius() const {
  return this->radius;
};

void Meteor::update() {
  this->velocity += this->acceleration;
  this->position += this->velocity;
  this->acceleration = {0.0, 0.0};
  if (this->check_bounds())
    this->mark_for_destroy();
};

bool Meteor::check_bounds() {
  const int leeway = 0;
  constexpr int max_x = DEFINED::WIN_W + leeway;
  constexpr int min_x = -DEFINED::WIN_W - leeway;
  constexpr int max_y = DEFINED::WIN_H + leeway;
  constexpr int min_y = -DEFINED::WIN_H - leeway;

  return (position.x > max_x || position.y > max_y || position.x < min_x ||
          position.y < min_y);
}

void Meteor::draw(SDL_Renderer* render) const {
  draw_filled_circle(render, this->position, this->radius);
};

void MeteorManager::create_meteor(Vetor p, Vetor v, Vetor a, double r) {
  std::unique_ptr<Meteor> new_meteor = std::make_unique<Meteor>(p, v, a, r);
  std::cout << "Created meteor " << new_meteor.get() << std::endl;
  this->meteor_list.push_back(std::move(new_meteor));
  // this->meteor_list.push_back(std::make_unique<Meteor>(p, v, a, r));
};

void MeteorManager::destroy_meteor(std::unique_ptr<Meteor>& meteor) {
  for (auto m = this->meteor_list.begin(); m != this->meteor_list.end(); m++) {
    if (m->get() == meteor.get()) {
      std::cout << "Destroyed meteor " << meteor.get() << std::endl;
      this->meteor_list.erase(m);
      return;
    }
  }
  // auto it = std::find_if(meteor_list.begin(), meteor_list.end(),
  //                        [&meteor](const std::unique_ptr<Meteor>& m) {
  //                          return m.get() == meteor.get();
  //                        });

  // if (it != meteor_list.end()) {
  //   it = meteor_list.erase(it);  // Remove the meteor from the list
  // }
};

std::vector<std::unique_ptr<Meteor>>& MeteorManager::return_list() {
  return this->meteor_list;
};
