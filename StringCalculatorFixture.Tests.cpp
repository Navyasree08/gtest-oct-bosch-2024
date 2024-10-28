#include "StringCalculator.h"
#include <gtest/gtest.h>

class string_calculator_add :  public ::testing::Test{
protected:
    StringCalculator *objUnderTest;
    void SetUp() override
    {
      objUnderTest = new StringCalculator();
    }
    void TearDown() 
    {
      delete objUnderTest;
    }
};

//TEST(TestSuiteName, TestCaseName)
TEST_F(string_calculator_add,positive_cases){
    ASSERT_EQ(objUnderTest->Add(""), 0);
    ASSERT_EQ(objUnderTest->Add("0"), 0);
    ASSERT_EQ(objUnderTest->Add("1"), 1);
    ASSERT_EQ(objUnderTest->Add("1,2"), 3);
    ASSERT_EQ(objUnderTest->Add("//;\n1;2"), 3);
    ASSERT_EQ(objUnderTest->Add("42,1001,3",45);
    ASSERT_EQ(objUnderTest->Add("//[***]\n8***2***3"), 13);
    ASSERT_EQ(objUnderTest->Add("//[*][%]\n4*2%3"), 9);
    ASSERT_EQ(objUnderTest->Add("//[**][%^]\n4**1%^9"), 14);
}

TEST_F(string_calculator_add, ThrowsExceptionForNegativeNumbers) {
    objUnderTest->Add("1,-2,-4,5");
    ASSERT_THROW(objUnderTest->Add("1,-2,-4,5"), std::invalid_argument);
    try {
        objUnderTest->Add("1,-2,-4,5");
    } catch (const std::invalid_argument& e) {
        EXPECT_STREQ(e.what(), "Negatives not allowed: -2,-4");
    }
}
    
