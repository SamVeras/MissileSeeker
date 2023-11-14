#include <iostream>
#include "entities.h"
#include "structures.h"

int main() {
  Point v1;
  v1.x = 7;
  v1.y = 5;
  std::cout << "x: " << v1.x << " y: " << v1.y << std::endl;
  std::cout << "mag: " << v1.get_magnitude() << std::endl;
  v1.set_magnitude(4);
  std::cout << "new mag(4): " << v1.get_magnitude() << std::endl;
  std::cout << "x: " << v1.x << " y: " << v1.y << std::endl;
  return 0;
}

// TESTAR GET MAGNITUDE E SET MAGNITUDE O PROBLEMA EH LA