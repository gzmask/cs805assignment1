#include <iostream>
#include "matrix.h"
int main(){
  Point vrp = {6.0, 10.0, -5.0};
  auto mt = get_T(vrp);
  for (auto row : mt) {
    for (auto num : row) {
      std::cout<<num<<',';
    }
    std::cout<<std::endl;
  }
  return 0;
}
