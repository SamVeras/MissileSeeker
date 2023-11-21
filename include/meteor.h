#pragma once
#include <memory>
#include <vector>
#include "SDL_wrappers.h"
#include "mobile.h"

class Meteor : public Mobile {
 protected:
  double radius;
  void explode();

 public:
  Meteor(Vetor pos, Vetor vel, Vetor acc, double radius);

  const double& get_radius() const;

  void draw(SDL_Renderer* render) const override final;
};

class MeteorManager {  // fazer mais genérico pra poder usar em qlqr classe!
 private:
  std::vector<std::unique_ptr<Meteor>> meteor_list;

 public:
  void create_meteor(Vetor p, Vetor v, Vetor a, double r);
  void destroy_meteor(std::unique_ptr<Meteor>& meteor);
  std::vector<std::unique_ptr<Meteor>>& return_list();
};
