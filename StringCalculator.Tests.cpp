#include "StringCalculator.h"
#include <gtest/gtest.h>

TEST(string_calculator_ass,when_passed_a_single_number_returns_0_for_Empty){
//Arrange
  StringCalculator  objUnderTests;
  string input = "";
  int expectedValue = 0;


  //ACT
  int actualValue = objUnderTests.Add(input);

  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}
