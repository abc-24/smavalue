#ifndef ADDITIONAL_SMA_VALUE_HPP
#define ADDITIONAL_SMA_VALUE_HPP

#include <bits/stdc++.h>

#include <limits>
#include <typeinfo>

#include "smavalue.hpp"

using namespace std;

template <typename T>
void generateValue(const int &lenSize, T *mass) {
  default_random_engine generator;
  uniform_real_distribution<T> distribution(numeric_limits<T>::min(),
                                            numeric_limits<T>::max());

  for (int i = 0; i < lenSize; i++, mass++) *mass = distribution(generator);
}

template <typename T>
void startEffiency(const T *mass) {
  const int N = 1000000;
  const int lenData[]{4, 8, 16, 32, 64, 128};

  cout << "Старт теста для типа " << typeid(*mass).name() << "\n";

  for (const int &len : lenData) {
    long totalTime = 0;
    for (int i = 0; i < N; ++i) {
      auto start = chrono::steady_clock::now();
      smaValue(len, mass);
      auto finish = chrono::steady_clock::now();
      totalTime +=
          chrono::duration_cast<chrono::microseconds>(finish - start).count();
    }

    double effiency = N / totalTime * 1000000.0;
    // cout << "Время выполнения " << totalTime << " мкс для окна шириной " <<
    // len << " \n";
    // cout << "Производительность " << effiency << " отсчетов в секунду\n";
    cout << effiency << "\n";
  }
  cout << "\n";
}

#endif