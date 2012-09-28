#include "util.h"
#include <math.h>

//get u,v,n from two non-collinear vectors
UVN get_uvn(Vecotr V1, Vecotr V2) {

  //get n, which is just normalized V1
  Vecotr n = normalize(V1); 

  //get u, which is normalized V2 x V1
  Vecotr u = normalize(cross_product(V2, V1));

  //get v, which is normalized n x u
  Vecotr v = normalize(cross_product(n, u));

  return {u,v,n};
}

//normalize a Vecotr
Vecotr normalize(Vecotr x) {
  return { x[0]/get_length(x), 
           x[1]/get_length(x), 
           x[2]/get_length(x) }; 
}

//calculates cross product of two Vecotrs
Vecotr cross_product(Vecotr x, Vecotr y) {
  return { x[1]*y[2] - x[2]*y[1],
           x[2]*y[0] - x[0]*y[2],
           x[0]*y[1] - x[1]*y[0]};
}

//calculates length of a Vecotr
float get_length(Vecotr x) {
  return sqrt(pow(x[0],2)+pow(x[1],2)+pow(x[2],2));
}
