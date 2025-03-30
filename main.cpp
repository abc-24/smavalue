#include "EstimateEfficiency.hpp"
#include "generateOutput.hpp"
#include "smaValue.hpp"

#define MIN 4
#define MAX 128

int main() {
  const int N = 1000000;
  const vector<int> LENDATA{MIN, 8, 16, 32, 64, MAX};

  float massF[MAX];
  double massD[MAX];

  generateValue(MAX, massF);
  generateValue(MAX, massD);

  EstimateEfficiency estimateF(N, LENDATA);
  EstimateEfficiency estimateD(N, LENDATA);

  estimateF.run(massF);
  estimateD.run(massD);

  outputResult(estimateF);
  outputResult(estimateD);

  return 0;
}