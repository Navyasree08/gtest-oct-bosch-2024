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

TEST(string_calculator_ass,when_passed_two_comma_delimited_numbers){
//Arrange
  StringCalculator  objUnderTests;
  string input = "1,2";
  int expectedValue = 3;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_delimited_with_newline_and_comma){
//Arrange
  StringCalculator  objUnderTests;
  string input = "1\n2,5";
  int expectedValue = 8;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_a_delimiter){
  //Arrange
  StringCalculator  objUnderTests;
  string input = "//;\n1;2";
  int expectedValue = 3;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}


TEST(string_calculator_ass,when_passed_numbers_over_1000){
  //Arrange
  StringCalculator  objUnderTests;
  string input = "42,1001,3";
  int expectedValue = 45;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_multicharacter_delimiter){
  //Arrange
  StringCalculator  objUnderTests;
  string input = "//[***]\n8***2***3";
  int expectedValue = 13;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_multiple_delimiters){
  //Arrange
  StringCalculator  objUnderTests;
  string input = "//[*][%]\n4*2%3";
  int expectedValue = 9;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_multiple_multicharacter_delimiters){
  //Arrange
  StringCalculator  objUnderTests;
  string input ="//[**][%^]\n4**1%^9";
  int expectedValue = 14;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  ASSERT_EQ(actualValue,expectedValue);
}

TEST(string_calculator_ass,when_passed_negative_numbers){
  //Arrange
  StringCalculator  objUnderTests;
  string input ="1,-2,-4,5";
  int expectedValue = 14;
  //ACT
  int actualValue = objUnderTests.Add(input);
  //ASSERT
  EXPECT_ANY_THROW({objUnderTests.Add(input)}, "Negatives not allowed: -2,-4");

}
