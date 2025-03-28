#include <chrono>
#include <iostream>

#include "additional.hpp"
#include "smavalue.hpp"

int main() {

  vector<float> vFloat(128);
  vector<double> vDouble(128);

  float massF[128];
  double massD[128];

  generateValue(128, &massF[0]);
  generateValue(128, &massD[0]);

  // startEffiency(&massD[0]);
  startEffiency(&massF[0]);

  return 0;
}