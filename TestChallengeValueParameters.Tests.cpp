#include "TestChallenge.h"
#include <gtest/gtest.h>

TEST(TestSuite,TestCase){
  int a = 10,b =20;
  int *result;
  add(a,b,&result)
ASSERT_EQ(&result,30);
}

