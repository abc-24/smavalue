#ifndef GENERATE_OUTPUT_HPP
#define GENERATE_OUTPUT_HPP

#include <bits/stdc++.h>

#include <limits>

using namespace std;

template <typename T>
void generateValue(const int &lenSize, T *mass) {
  default_random_engine generator;
  uniform_real_distribution<T> distribution(numeric_limits<T>::min(),
                                            numeric_limits<T>::max());

  for (int i = 0; i < lenSize; i++, mass++) *mass = distribution(generator);
}

void outputResult(const EstimateEfficiency &result) {
  cout << format("Старт расчета производительности для типа {}\n",
                 result.getTypeData());
  cout << format(
      "Ширина | Время выполнения, мкс | Производительность, млн. отсчетов "
      "в секунду \n");

  auto iterL = result.getLenghtData().cbegin();
  auto iterT = result.getTimeMcrS().cbegin();
  auto iterE = result.getEfficiencyMlnPcs().cbegin();
  for (; iterL != result.getLenghtData().cend(); iterL++, iterT++, iterE++) {
    cout << format("{:>6} | {:>21} | {}\n", *iterL, *iterT, *iterE);
  }
}

#endif