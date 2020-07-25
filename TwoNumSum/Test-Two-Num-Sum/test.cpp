#include "pch.h"

#if 0
TEST(TwoNumSum, DISABLED_TestCaseOne)
{
	std::vector<int> sampleTestInput = { 3,5,-4,8,11,1,-1,6 };
	Solve solve1;
	std::vector<int> output = {-1, 11};
	EXPECT_EQ(output,solve1.twoNumberSumBadSolve(sampleTestInput, 10));
}
#endif
TEST(one, two)
{
	std::vector<int> h = {3, 5, -4, 8, 11, 1, -1, 6};
	std::vector<int> aim = { -1, 11 };
	Solve solve1;
	EXPECT_EQ(1, 1);
	std::vector<int> output = solve1.twoNumberSumBadSolve(h, 10);
	EXPECT_EQ(aim,output);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}