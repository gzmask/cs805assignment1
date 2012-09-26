#include <iostream>
#include <typeinfo>//debugging only
#include "get_uvn.h"

int main () {
  Point V1;
  decltype(V1) V2;//c11: V2 is of same type of V1

  V1 = {1,2,3};
  V1 = {3,2,1};

  auto uvn = get_uvn(V1, V2);//c11: compiler will replace 'auto' with the right type

  for (auto point : uvn) {//c11:for each point in uvn
    //std::cout<<typeid(point).name()<<std::endl;
    for (auto num : point) {//c11:for each number in point
      std::cout<<num<<std::endl;
    }
  }

  return 0;
}
