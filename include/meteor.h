#pragma once
#include <memory>
#include <vector>
#include "SDL_wrappers.h"
#include "mobile.h"

class Meteor : public Mobile {
 protected:
  double radius;
  void explode();
  // bool check_bounds() const;
  bool check_bottom_screen() const;

 public:
  const double& get_radius() const;
  void update() override final;
  void draw(SDL_Renderer* render) const override final;

  Meteor(Vetor pos, Vetor vel, Vetor acc, double radius);
};

class MeteorManager {  // Fazer mais genérico pra poder usar em qlqr classe?
 private:
  std::vector<std::unique_ptr<Meteor>> meteor_list;

 public:
  std::vector<std::unique_ptr<Meteor>>& return_list();  // Getter da lista
  void create_meteor(Vetor p, Vetor v, Vetor a, double r);
  void destroy_meteor(std::unique_ptr<Meteor>& meteor);
};
