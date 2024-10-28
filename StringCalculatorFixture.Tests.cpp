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

TEST_F(StringCalculatorAddFixture, Returns_1_For_1){
  string input = "1";
  int expectedValue = 1;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, two_comma_delimited_numbers){
  string input = "1,2";
  int expectedValue = 3;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, delimited_with_newline_and_comma){
  string input = "1\n2,5";
  int expectedValue = 8;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, delimiter){
  string input = "//;\n2,5";
  int expectedValue = 7;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Numbers_above_1000){
  string input = "42,1001,3";
  int expectedValue = 45;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Multicharacter_delimiter){
  string input = "//[***]\n8***2***3";
  int expectedValue = 13;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Multiple_delimiter){
  string input = "//[*][%]\n4*2%3";
  int expectedValue = 9;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Multiple_Multicharacter_delimiter){
  string input = "//[**][%^]\n4**1%^9";
  int expectedValue = 14;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, Multiple_Multicharacter_delimiter){
  string input = "//[**][%^]\n4**1%^9";
  int expectedValue = 14;
  int actualValue = objUnderTest->Add(input);
  ASSERT_EQ(actualValue, expectedValue);
}

TEST_F(StringCalculatorAddFixture, negative_numbers){
  string input = "1,-2,-4,5";
  ASSERT_THROW(objUnderTest->Add(input), std::invalid_argument);
}

TEST_F(StringCalculatorAddFixture, negative_numbers_Try_catch){
  string input = "1,-2,-4,5";
    try {
        objUnderTest->Add(input);
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Negatives not allowed: -2,-4");
    }
}
