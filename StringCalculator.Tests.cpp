#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_ass,when_passed_a_single_number_returns_0){
//Arrange
  StringCalculator  objUnderTests;
  string input = "";
  int expectedValue = 0;


  //ACT
  int actualValue = objUnderTests.Add(input);

  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
  input = "0";
  actualValue = objUnderTests.Add(input);
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_a_single_number_returns_0_for_1){
//Arrange
  StringCalculator  objUnderTests;
  string input = "1";
  int expectedValue = 1;


  //ACT
  int actualValue = objUnderTests.Add(input);

  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}
