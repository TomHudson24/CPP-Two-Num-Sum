#include "Solve.h"

//Task is:
/*
Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. If any two numbers in 
the input array sum up to the taret sum, the function should return them in an array, in any order. If no two numbers sum up to the target sum, 
the function should return an empty array.

Note that the target sum has to be obtained by summing two different integers in the array; you can't add a single integer to itself in order to 
obtain the target sum.

You can assume that there wll be at most one pair of numbers summing up to the target sum.
*/

//Solves:
/*
The first and second solve are using nested for loops. This is a poor solution for Time Complexity (Sub-quadratic time) however 
Space Complexity for it is optimal (Constant space).

The third solve uses a hashmap to store values so they can be checked against. This reduces the need for a second for loop, improving
Time Complexity (Linear time) but the Space Complexity is worse as the hash map will be storing values (Linear space).

The fourth and final solve uses the sorting algorithm built into the standard template library. This can be assumed as an improve
on Time Complexity when compared to the Nested For Loop solve (Quasilinear time) but worse than the Hash solve. The Space Complexity
is Constant space meaning it is better than the Hash solve if Space is more important than Time.
*/
//Readable Nested For Loop Solve.
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

//Nested For Loop "optimal" Solve.		TC = O(N^2) | SC = O(1)
std::vector<int> Solve::twoNumberSumBadSolve2(std::vector<int> array, int targetSum)
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

//Best TC solve - using hash map		TC = O(N) | SC = O(N)
std::vector<int>Solve::twoNumberSumHashSolve(std::vector<int> array, int targetSum)
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

//Best SC solve - using sorting			TC = O(nLog(n)) | SC = O(1)
std::vector<int>Solve::twoNumberSumSortSolve(std::vector<int> array, int targetSum)
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