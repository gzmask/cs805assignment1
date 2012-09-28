#include <iostream>
#include <typeinfo>//debugging only
#include "util.h"

int main () {
  Vecotr V1;
  decltype(V1) V2;// V2 is of same type of V1

  V1 = {0,0,1000};
  V2 = {0,1,1};

  //call our function to get the uvn. auto will be replaced by the actual time by preprocessor.
  auto uvn = get_uvn(V1, V2);

  for (auto vecotr : uvn) {//for each Vecotr in uvn
    for (auto num : vecotr) {//for each number in Vecotr
      std::cout<<num<<',';
    }
    std::cout<<std::endl;
  }

  return 0;
}
