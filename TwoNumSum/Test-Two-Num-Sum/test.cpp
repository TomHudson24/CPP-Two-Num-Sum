#include "pch.h"
std::vector<int> twoNumberSumBadSolve(std::vector<int> array, int targetSum)
{
	//edge case of only 1 entry, can't do comparison so return an empty array
	if (array.size() == 1)
	{
		return {};
	}

	//init a new array to add data too
	std::vector<int> returnArray;

	//nested loop solution
	for (int i = 0; i < array.size(); i++)
	{
		int currentInt = array[i];//value at start of array
		for (int j = array.size() - 1; j > 0; j--)
		{
			int checkInt = array[j];//value at end of the array
			if (targetSum == (currentInt + checkInt) && currentInt != checkInt)
			{
				std::vector<int>::iterator it;

				it = std::find(returnArray.begin(), returnArray.end(), currentInt);
				if (it == returnArray.end())//the value in currentInt has not already been added to the new array
				{
					returnArray.push_back(currentInt);
				}
				it = std::find(returnArray.begin(), returnArray.end(), checkInt);
				if (it == returnArray.end())//the value in checkInt has not already been added to the new array
				{
					returnArray.push_back(checkInt);
				}

			}
		}
	}
	return returnArray;
}

TEST(TwoNumberSumTest, TestCaseOne)
{
	std::vector<int> inputArray = {3, 5, -4, 8, 11, 1, -1, 6};
	std::vector<int> aim = { 11, -1 };
	
	std::vector<int> output = twoNumberSumBadSolve(inputArray, 10);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseTwo)
{
	std::vector<int> inputArray = { 4, 6 };
	std::vector<int> aim = { 4, 6 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 10);
	EXPECT_EQ(aim, output);

}
TEST(TwoNumberSumTest, TestCaseThree)
{
	std::vector<int> inputArray = { 4, 6, 1};
	std::vector<int> aim = { 4, 1 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 5);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseFour)
{
	std::vector<int> inputArray = { 4,6,1,-3 };
	std::vector<int> aim = { 6, -3 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 3);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseFive)
{
	std::vector<int> inputArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> aim = { 8,9 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 17);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseSix)
{
	std::vector<int> inputArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	std::vector<int> aim = { 3,15 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 18);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseSeven)
{
	std::vector<int> inputArray = { -7, -5, -3, -1, 0, 1, 3, 5, 7 };
	std::vector<int> aim = { -5, 0 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, -5);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseEight)
{
	std::vector<int> inputArray = { 21, 301, 12, 4, 65, 56, 210, 356, 9, -47 };
	std::vector<int> aim = { 210, -47 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 163);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseNine)
{
	std::vector<int> inputArray = { -21, 301, 12, 4, 65, 56, 210, 356, 9, -47 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 164);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseTen)
{
	std::vector<int> inputArray = { 3, 5, -4, 8, 11, 1, -1, 6 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseEleven)
{
	std::vector<int> inputArray = {14};
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	EXPECT_EQ(aim, output);
}
TEST(TwoNumberSumTest, TestCaseTwelve)
{
	std::vector<int> inputArray = { 15 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	EXPECT_EQ(aim, output);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}