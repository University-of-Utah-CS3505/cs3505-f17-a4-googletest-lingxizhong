/*
Assignment 04 - Travis and Google TEST
Lingxi Zhong and Osama Kergaye
U0770136 | U(Osama put ur UID here)
*/

#include "Students.h"
#include "gtest/gtest.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


// Add User Tests:
TEST(addUsers, addUserBasicTests) {
  Students stu;
  string testUser = "Bob";
  stu.addUser(testUser, 1);
  EXPECT_TRUE(stu.nameExists(testUser));
  stu.addUser("TestString", 2);
  EXPECT_TRUE(stu.nameExists("TestString"));
  EXPECT_EQ(2, stu.numberOfNames());
}

TEST(addUsers, addUserDupID) {
  Students stu;
  stu.addUser("Charlie", 1);
  stu.addUser("Tango", 1);
  EXPECT_EQ(1, stu.idForName("Charlie"));
  EXPECT_EQ(1, stu.idForName("Tango"));
}

TEST(addUsers, addUserStressTest) {
  Students stu;
  for(int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for(int j = 0; j < 100000; j++) {
    string usernum = "user" + to_string(j);
    EXPECT_TRUE(stu.nameExists(usernum));
  }
}

TEST(addUsers, addUserStressTest1Mill) {
  Students stu;
  for(int i = 0; i < 1000000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for(int j = 0; j < 1000000; j++) {
    string usernum = "user" + to_string(j);
    EXPECT_TRUE(stu.nameExists(usernum));
  }
}

TEST(addUsers, addUserWithSameName) {
  Students stu;
  stu.addUser("user", 1);
  stu.addUser("user", 2);
  EXPECT_EQ(1, stu.idForName("user"));
}

TEST(addUsers, addUserWithBlankString) {
  Students stu;
  stu.addUser("", 1);
  string empty;
  stu.addUser(empty, 1);
  EXPECT_EQ(0, stu.numberOfNames());
}

//AddPhoneNumber Tests
TEST(addPhoneNumbers, addPhoneNumbersBasic) {
  Students stu;
  stu.addUser("user", 1);
  stu.addPhoneNumbers(1, "123-456-7890");
  EXPECT_EQ("123-456-7890", stu.phoneForName("user"));
}

TEST(addPhoneNumbers, addPhoneNumberStress) {
  Students stu;
  for (int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for (int j = 0; j < 100000; j++) {
    stu.addPhoneNumbers(j, "123-456-7890");
  }
  for (int h = 0; h < 100000; h++) {
    EXPECT_EQ("123-456-7890", stu.phoneForName("user"+(to_string(h))));
  }
}

//Add Grade Tests
TEST(addGrade, basicFunctionality) {
  Students stu;
  stu.addUser("user", 1);
  stu.addGrade(1, 'A');
  EXPECT_EQ('A', stu.gradeForName("user"));
}

TEST(addGrade, addGradeStressTest) {
  Students stu;
  for(int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
    stu.addGrade(i, 'F'); // FAIL EVERYONE >:D
  }
  for(int j = 0; j < 100000; j++) {
    EXPECT_EQ('F', stu.gradeForName("user"+(to_string(j))));
  }
}

// id For Names
TEST(idForNames, basicFunctionality) {
  Students stu;
  stu.addUser("user", 1);
  EXPECT_EQ(1, stu.idForName("user"));
}

TEST(idForNames, stressTest) {
  Students stu;
  for(int i = 0; i  < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for(int j = 0; j < 100000; j++) {
    ASSERT_EQ(j, stu.idForName("user"+(to_string(j))));
  }
}

TEST(idForNames, exceptionTest) {
  Students stu;
  EXPECT_THROW(stu.idForName("user"), std::out_of_range);
}

//Grade For Name

TEST(gradeForName, basicFunctionality) {
  Students stu;
  stu.addUser("user", 1);
  stu.addGrade(1, 'A');
  EXPECT_EQ('A', stu.gradeForName("user"));
}

TEST(gradeForName, stressTest) {
  Students stu;
  for (int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
    stu.addGrade(i, 'F');
  }
  for (int j = 0; j < 100000; j++) {
    EXPECT_EQ('F', stu.gradeForName("user" + (to_string(j))));
  }
}

TEST(gradeForName, exceptionTest) {
  Students stu;
  stu.addUser("user", 1);
  EXPECT_THROW(stu.gradeForName("user"), std::out_of_range);
  EXPECT_THROW(stu.gradeForName("user2"), std::out_of_range);
}

// Phone for Name

TEST(phoneForName, basicFunctionality) {
  Students stu;
  stu.addUser("user", 1);
  stu.addPhoneNumbers(1, "123-456-7890");
  EXPECT_EQ("123-456-7890", stu.phoneForName("user"));
}

TEST(phoneForName, phoneForNameStress) {
  Students stu;
  for (int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for (int j = 0; j < 100000; j++) {
    stu.addPhoneNumbers(j, "123-456-7890");
  }
  for (int h = 0; h < 100000; h++) {
    EXPECT_EQ("123-456-7890", stu.phoneForName("user"+(to_string(h))));
  }
}

TEST(phoneForName, phoneForNameException) {
  Students stu;
  EXPECT_THROW(stu.phoneForName("user"), std::out_of_range);
}

// Name Exists

TEST(nameExists, basicFunctionality) {
  Students stu;
  stu.addUser("user", 1);
  EXPECT_TRUE(stu.nameExists("user"));
  EXPECT_FALSE(stu.nameExists("user2"));
}

TEST(nameExists, edgeCaseoFID) {
  Students stu;
  stu.addUser("user", 123);
  EXPECT_FALSE(stu.nameExists("123"));
}

//full record

TEST(fullRecord, fullRecordFalseTest) {
  Students stu;
  string user;
  unsigned int id;
  string phone;
  char grade;
  EXPECT_FALSE(stu.fullRecord(user,id,phone,grade));
}

TEST(fullRecord, fullRecordWithInfo) {
  Students stu;
  stu.addUser("user", 1);
  stu.addPhoneNumbers(1, "123-456-7890");
  stu.addGrade(1, 'A');
  string user = "user";
  unsigned int id;
  string phone;
  char grade;
  EXPECT_TRUE(stu.fullRecord(user, id, phone, grade));
  EXPECT_EQ(1, id);
  EXPECT_EQ("123-456-7890", phone);
  EXPECT_EQ('A', grade);
}

// Number of names
TEST(numberOfNames, numberOfNamesStressTest) {
  Students stu;
  for(int i = 0; i < 100000; i++) {
    stu.addUser("user"+to_string(i), i);
  }
  for(int j = 0; j < 100000; j++) {
    EXPECT_TRUE(stu.nameExists("user"+(to_string(j))));
  }
  EXPECT_EQ(100000, stu.numberOfNames());
}
