#include "StringCalculator.h"
#include <gtest/gtest.h>

class StringCalculatorAddFixture: public testing::Test{
  protected: 
    StringCalculator *objUnderTest;
  void SetUp() override {
  objUnderTest = new StringCalculator();
  }
  void TearDown(){
    delete objUnderTest;
  }
};

TEST_F(StringCalculatorAddFixture, Returns_0_For_Empty){
  string input = "";
  int expectedValue = 0;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Returns_0_For_0){
  string input = "0";
  int expectedValue = 0;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}
