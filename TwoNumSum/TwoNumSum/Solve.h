#pragma once
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solve {

public:
	std::vector<int> twoNumberSumBadSolve(std::vector<int> array, int targetSum);
	std::vector<int> twoNumberSumBadSolve2(std::vector<int> array, int targetSum);

	std::vector<int>twoNumberSumHashSolve(std::vector<int> array, int targetSum);

	std::vector<int>twoNumberSumSortSolve(std::vector<int> array, int targetSum);
};


