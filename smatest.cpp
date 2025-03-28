#include <gtest/gtest.h>
#include <math.h>

#include "smavalue.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

class testSma : public testing::Test {
 public:
};

TEST(testSma, testIncorrect) {
  float *error = nullptr;
  auto sma = smaValue(4, error);

  EXPECT_EQ(true, std::isnan(sma));
}

TEST(testSma, test4f) {
  float mass[4] = {1, 1, 1, 2};
  auto sma = smaValue(4, &mass[0]);

  EXPECT_EQ(sma, 1.25);
}

TEST(testSma, test4fOverflow) {
  float mass[4] = {340282346638528859811704183484516925440.0,
                   340282346638528859811704183484516925440.0,
                   340282346638528859811704183484516925440.0,
                   340282346638528859811704183484516925440.0};
  auto sma = smaValue(4, &mass[0]);

  EXPECT_EQ(sma, 340282346638528859811704183484516925440.0);
}

TEST(testSma, test8d) {
  double mass[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  auto sma = smaValue(8, &mass[0]);

  EXPECT_EQ(sma, 4.5);
}

TEST(testSma, test8dOverFlow) {
  double mass[8] = {1.7e+300, 1.7e+300, 1.7e+300, 1.7e+300,
                    1.7e+300, 1.7e+300, 1.7e+300, 1.7e+300};
  auto sma = smaValue(8, &mass[0]);

  EXPECT_EQ(sma, 1.7e+300);
}
