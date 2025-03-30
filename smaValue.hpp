#ifndef SMAVALUE_HPP
#define SMAVALUE_HPP

#include <cmath>

auto smaValue(const int &lenData, const auto *inputData) {
  if (!inputData) {
    return sqrt(-1);
  }

  auto sum = *inputData;
  inputData++;
  for (int i = 2; i <= lenData; i++, inputData++) {
    sum += (*inputData - sum) / i;
  }

  return 1.0 * sum;
}

#endif
