/*
Assignment 04 - Travis and Google TEST
Lingxi Zhong and Osama Kergaye
U0770136 | U(Osama put ur UID here)
*/

#include "Students.h"
#include "gtest/gtest.h"
int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(Constructor, Basic Constructor Testing){
  Students* stu = new Students();
  //EXPECT_EQ();
}
