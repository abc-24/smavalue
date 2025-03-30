#ifndef ESTIMATEEFFICIENCY_HPP
#define ESTIMATEEFFICIENCY_HPP

#include <chrono>
#include <vector>

#include "smaValue.hpp"

using namespace std;

class EstimateEfficiency {
  vector<long> timeMicroSec;
  vector<long> efficiencyMlnPcs;
  char typeData;
  int N;
  vector<int> lenghtData;

 public:
  explicit EstimateEfficiency(const int &_N, const vector<int> &_lenghtData)
      : N(_N), lenghtData(_lenghtData) {}

  const vector<long> &getTimeMcrS() const { return timeMicroSec; }
  const vector<long> &getEfficiencyMlnPcs() const { return efficiencyMlnPcs; }
  const vector<int> &getLenghtData() const { return lenghtData; }
  const char &getTypeData() const { return typeData; }

  void run(const auto *inputData) {
    typeData = *typeid(*inputData).name();

    for (const int &lenData : lenghtData) {
      long totalMircoSec = 0;
      for (int i = 0; i < N; ++i) {
        auto start = chrono::steady_clock::now();
        smaValue(lenData, inputData);
        auto finish = chrono::steady_clock::now();
        totalMircoSec +=
            chrono::duration_cast<chrono::microseconds>(finish - start).count();
      }

      timeMicroSec.push_back(totalMircoSec);
      efficiencyMlnPcs.emplace_back(static_cast<long>(N / totalMircoSec));
    }
  }
};

#endif