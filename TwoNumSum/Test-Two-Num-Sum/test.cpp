#include "pch.h"
//basic solve using nested for loops
//my solve
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
//better nested loop solve (less variable creation)
std::vector<int> twoNumberSumBadSolve2(std::vector<int> array, int targetSum)
{
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = array.size() - 1; j > 0; j--)
		{
			if (array[i] + array[j] == targetSum && array[i] != array[j])
			{
				return { array[i],array[j] };
			}
		}
	}
	return {};
}

//Best TC solve - using hash map
std::vector<int>twoNumberSumHashSolve(std::vector<int> array, int targetSum)
{
	std::unordered_set<int> numbers;
	//range based for loop
	for (int num : array)
	{
		int potentialMatch = targetSum - num;//current numbers match 
		if (numbers.find(potentialMatch) != numbers.end())//does the number exist in the set
		{
			return { potentialMatch, num };//number match has been found so return the pair 
		}
		else
		{
			numbers.insert(num);//no current match in the set so add this to "seen" numbers set
		}

	}
	return {};//nothing hit so can't be done

}
//Best SC solve - using array sorting
std::vector<int>twoNumberSumSortSolve(std::vector<int> array, int targetSum)
{
	std::sort(array.begin(), array.end());//sort the array, it is assumed that this is done in O(N(log n)) TC
	int left = 0, right = array.size() - 1;
	while (left < right)
	{
		int currentSum = array[left] + array[right];//sum the current iteration of values
		if (currentSum == targetSum)
		{
			return { array[left], array[right] };
		}
		else if (currentSum < targetSum)//move the left value up the array
		{
			left++;
		}
		else if (currentSum > targetSum)//move the right value down the array
		{
			right--;
		}
	}

	return {};
}

TEST(TwoNumberSumTest, TestCaseOne)
{
	std::vector<int> inputArray = {3, 5, -4, 8, 11, 1, -1, 6};
	std::vector<int> aim = { 11, -1 };
	std::vector<int> aimReverse = { -1, 11 };
	
	std::vector<int> output = twoNumberSumBadSolve(inputArray, 10);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 10);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 10);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 10);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aimReverse, outputSort);

}
TEST(TwoNumberSumTest, TestCaseTwo)
{
	std::vector<int> inputArray = { 4, 6 };
	std::vector<int> aim = { 4, 6 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 10);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 10);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 10);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 10);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);

}
TEST(TwoNumberSumTest, TestCaseThree)
{
	std::vector<int> inputArray = { 4, 6, 1};
	std::vector<int> aim = { 4, 1 };
	std::vector<int> aimReverse = { 1, 4 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 5);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 5);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 5);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 5);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aimReverse, outputSort);

}
TEST(TwoNumberSumTest, TestCaseFour)
{
	std::vector<int> inputArray = { 4,6,1,-3 };
	std::vector<int> aim = { 6, -3 };
	std::vector<int> aimReverse = { -3, 6 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 3);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 3);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 3);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 3);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aimReverse, outputSort);

}
TEST(TwoNumberSumTest, TestCaseFive)
{
	std::vector<int> inputArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::vector<int> aim = { 8,9 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 17);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 17);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 17);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 17);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseSix)
{
	std::vector<int> inputArray = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15 };
	std::vector<int> aim = { 3,15 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 18);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 18);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 18);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 18);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseSeven)
{
	std::vector<int> inputArray = { -7, -5, -3, -1, 0, 1, 3, 5, 7 };
	std::vector<int> aim = { -5, 0 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, -5);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, -5);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, -5);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, -5);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseEight)
{
	std::vector<int> inputArray = { 21, 301, 12, 4, 65, 56, 210, 356, 9, -47 };
	std::vector<int> aim = { 210, -47 };
	std::vector<int> aimReverse = { -47, 210 };

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 163);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 163);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 163);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 163);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aimReverse, outputSort);
}
TEST(TwoNumberSumTest, TestCaseNine)
{
	std::vector<int> inputArray = { -21, 301, 12, 4, 65, 56, 210, 356, 9, -47 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 164);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 164);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 164);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 164);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseTen)
{
	std::vector<int> inputArray = { 3, 5, -4, 8, 11, 1, -1, 6 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 15);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 15);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 15);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseEleven)
{
	std::vector<int> inputArray = {14};
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 15);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 15);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 15);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
TEST(TwoNumberSumTest, TestCaseTwelve)
{
	std::vector<int> inputArray = { 15 };
	std::vector<int> aim = {};

	std::vector<int> output = twoNumberSumBadSolve(inputArray, 15);
	std::vector<int> output2 = twoNumberSumBadSolve2(inputArray, 15);
	std::vector<int> outputHash = twoNumberSumHashSolve(inputArray, 15);
	std::vector<int> outputSort = twoNumberSumSortSolve(inputArray, 15);

	EXPECT_EQ(aim, output);
	EXPECT_EQ(aim, output2);
	EXPECT_EQ(aim, outputHash);
	EXPECT_EQ(aim, outputSort);
}
int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}