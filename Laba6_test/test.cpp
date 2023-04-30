/*#include "pch.h"
#include "../tmp.h"

TEST(TestCaseName, TestName) {
	Prey pr("����", Point2D(2, 5));
	
  EXPECT_EQ(pr.getx(),2);
  EXPECT_EQ(pr.gety(),5);

  pr.MoveTo(10, 55);

  EXPECT_EQ(pr.getx(), 10);
  EXPECT_EQ(pr.gety(), 55);

}

TEST(TestCaseName, TestName1) {
	Prey pr("����", Point2D(2, 5));

	EXPECT_EQ(pr.getx(), 2);
	EXPECT_EQ(pr.gety(), 6);

	pr.MoveTo(10, 55);

	EXPECT_EQ(pr.getx(), 10);
	EXPECT_EQ(pr.gety(), 55);

}*/

#include "gtest/gtest.h"
#include "test_Point2D/h"
#include "test_Prey/h"

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(& argc, argv);
	return RUN_ALL_TESTS();
}