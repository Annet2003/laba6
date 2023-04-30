#pragma once

#include "../Characters.h"

struct PreyTest : public testing::Test
{
	Prey* prey;
	void SetUp()
	{
		prey = new Prey("Tester ", Point2D())
	}
	void TearDown()
	{
		delete prey;
	}

};
TEST_F(PreyTest, init_class)
{
	EXPECT_STREQ(prey->getName().c_str(), "Tester Sergey");

	EXPECT_TRUE(prey->isNPC());
	ASSERT_TRUE(Point2D(7, 5) == prey->getLocation());
}