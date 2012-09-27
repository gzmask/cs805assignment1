#include <iostream>
#include <typeinfo>//debugging only
#include "util.h"

int main () {
  Point V1;
  decltype(V1) V2;//c11: V2 is of same type of V1

  V1 = {0,0,1};
  V2 = {0,1,1};

  auto uvn = get_uvn(V1, V2);//c11: compiler will replace 'auto' with the right type

  for (auto point : uvn) {//c11:for each point in uvn
    for (auto num : point) {//c11:for each number in point
      std::cout<<num<<',';
    }
    std::cout<<std::endl;
  }

  return 0;
}
