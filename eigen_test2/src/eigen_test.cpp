#include <Eigen/Dense>
#include <iostream>

using Eigen::MatrixXd;

int main() {
  int N = 5;
  const float pi=3.14159265358979323846;
  Eigen::VectorXf colVec = Eigen::VectorXf::LinSpaced(N,0,N-1);
  Eigen::VectorXf rowVec = Eigen::VectorXf::LinSpaced(N,0,N-1);
  Eigen::MatrixXf mn = colVec * rowVec.transpose();
  Eigen::MatrixXf mn_2pi_overN = mn*2.0*pi/(float)N;
  Eigen::MatrixXf M_dft_real =  mn_2pi_overN.array().cos();
  //   MatrixXd m =
  //       Eigen::MatrixXd::Constant(3000, 3000, 1.0);
  //   m = m.array().cos();
  std::cout << mn << std::endl;
  std::cout << mn_2pi_overN << std::endl;
  std::cout << M_dft_real << std::endl;
  return 0;
}