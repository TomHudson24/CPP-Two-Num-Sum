#include "Solve.h"

/*
Task is:
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in 
the input array sum up to the taret sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, 
the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array; you can't add a single integer to itself in order to 
obtain the target sum.

You can assume that there wll be at most one pair of numbers summing up to the target sum.
*/
std::vector<int> Solve::twoNumberSumBadSolve(std::vector<int> array, int targetSum)
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