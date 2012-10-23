#include "matrix.h"
int main(){
  //get camera test data points ready
  Point vrp = {6.0, 10.0, -5.0};
  Point vpn = {-6.0, -9.0, 5.0}; 
  Point vup = {0.0, 1.0, 0.0};

  //get matrix handy
  auto mt = get_T(vrp);
  auto mti = get_Ti(vrp);
  auto mr = get_R(vrp, vpn, vup);
  auto mri = get_Ri(vrp, vpn, vup);
  auto m_wc = get_M(vrp, vpn, vup);
  auto m_cw = get_Mi(vrp, vpn, vup);

  //print results
  pmatrix("translation matrix:", mt);
  pmatrix("inverse translation matrix:", mti);
  pmatrix("rotation matrix:", mr);
  pmatrix("inverse rotation matrix:", mri);
  pmatrix("world to camera matrix:", m_wc);
  pmatrix("camera to world matrix:", m_cw);

  //get light test data points ready
  Point lrp = {-10.0, 10.0, 0.0}; 
  Point lpn = {10.0, 9.0, 0.0}; 
  Point lup = {0.0, 1.0, 0.0};

  //get matrix handy
  auto m_wl = get_M(lrp, lpn, lup);
  auto m_lw = get_Mi(lrp, lpn, lup);

  //print results
  pmatrix("world to light matrix:", m_wl);
  pmatrix("light to world matrix:", m_lw);

  //print results
  pmatrix("camera to light matrix:", mul(m_wl, m_cw));
  pmatrix("light to camera matrix:", mul(m_wc, m_lw));

  //now test the points
  Row t1 = {0.0, 0.0, 0.0, 1.0}; 
  Row t2 = {0.0, 1.0, 0.0, 1.0}; 
  Row t3 = {1.0, 1.0, 1.0, 1.0};
  Row t4 = {1.0, 1.0, 0.0, 1.0};

  auto t1_ = mul(t1, m_wc);
  auto t2_ = mul(t2, m_wc);
  auto t3_ = mul(t3, m_wc);
  auto t4_ = mul(t4, m_wc);
  std::cout<<"test points at new camera coordinations:"<<std::endl;
  std::cout<<t1_[0]<<", "<<t1_[1]<<", "<<t1_[2]<<", "<<t1_[3]<<std::endl;
  std::cout<<t2_[0]<<", "<<t2_[1]<<", "<<t2_[2]<<", "<<t2_[3]<<std::endl;
  std::cout<<t3_[0]<<", "<<t3_[1]<<", "<<t3_[2]<<", "<<t3_[3]<<std::endl;
  std::cout<<t4_[0]<<", "<<t4_[1]<<", "<<t4_[2]<<", "<<t4_[3]<<std::endl;

  auto t1__ = mul(t1, m_wl);
  auto t2__ = mul(t2, m_wl);
  auto t3__ = mul(t3, m_wl);
  auto t4__ = mul(t4, m_wl);
  std::cout<<"test points at new light coordinations:"<<std::endl;
  std::cout<<t1__[0]<<", "<<t1__[1]<<", "<<t1__[2]<<", "<<t1__[3]<<std::endl;
  std::cout<<t2__[0]<<", "<<t2__[1]<<", "<<t2__[2]<<", "<<t2__[3]<<std::endl;
  std::cout<<t3__[0]<<", "<<t3__[1]<<", "<<t3__[2]<<", "<<t3__[3]<<std::endl;
  std::cout<<t4__[0]<<", "<<t4__[1]<<", "<<t4__[2]<<", "<<t4__[3]<<std::endl;

  return 0;
}
