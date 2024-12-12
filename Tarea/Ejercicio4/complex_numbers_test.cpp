#include "gtest/gtest.h"
#include "complex.h"

TEST(ComplexNumbersTest, ComplexAddition) {
  Complex a(3, 2);
  Complex b(1, 7);
  Complex result = a + b;

  EXPECT_EQ(result.getReal(), 4);
  EXPECT_EQ(result.getImag(), 9);
}

TEST(ComplexNumbersTest, ComplexSubtraction) {
  Complex a(5, 3);
  Complex b(2, 4);
  Complex result = a - b;

  EXPECT_EQ(result.getReal(), 3);
  EXPECT_EQ(result.getImag(), -1);
}

TEST(ComplexNumbersTest, ComplexOutput) {
  Complex a(3, 2);
  std::ostringstream os;
  os << a;

  EXPECT_EQ(os.str(), "3 + 2i");
}

TEST(ComplexNumbersTest, ComplexInput) {
  std::istringstream input("5 6");
  Complex a;
  input >> a;

  EXPECT_EQ(a.getReal(), 5);
  EXPECT_EQ(a.getImag(), 6);
}
