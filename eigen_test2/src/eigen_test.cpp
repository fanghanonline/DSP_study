#include <Eigen/Dense>
#include <fftw3.h>
#include <iostream>

using Eigen::MatrixXd;

int main() {
  int N = 5;
  const float pi = 3.14159265358979323846;
  Eigen::VectorXf colVec = Eigen::VectorXf::LinSpaced(N, 0, N - 1);
  Eigen::VectorXf rowVec = Eigen::VectorXf::LinSpaced(N, 0, N - 1);
  Eigen::MatrixXf mn = colVec * rowVec.transpose();
  Eigen::MatrixXf mn_2pi_overN = mn * 2.0 * pi / (float)N;
  Eigen::MatrixXf M_dft_real = mn_2pi_overN.array().cos();

  fftw_complex *in, *out;
  fftw_plan p;
  in = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
  out = (fftw_complex *)fftw_malloc(sizeof(fftw_complex) * N);
  p = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
  fftw_execute(p); /* repeat as needed */
  fftw_destroy_plan(p);
  fftw_free(in);
  fftw_free(out);

  return 0;
}