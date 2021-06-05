#include<iostream>
#include<vector>

int ClosestToZ(const std::vector<int>&sortedArr, int Z)
{
	if (sortedArr.empty())
		return -1;

	int low = 0;
	int high = sortedArr.size()-1;

	if (Z >= sortedArr[high])
		return sortedArr[high];

	if (Z <= sortedArr[low])
		return sortedArr[low];

	// low < Z < high

	while ((high - low) >= 2)
	{
		int mid = low + (high - low) / 2; /* (low + high)/2 */

		if (abs(Z - sortedArr[high]) <= abs(Z - sortedArr[low]))
			low = mid;
		else
			high = mid;
	}

	// (high - low) < 2 ;	...,(high),(low),....
	if (abs(Z - sortedArr[high]) <= abs(Z - sortedArr[low]))
		return sortedArr[high];
	return sortedArr[low];
}


void main()
{

	std::vector<int> vec = { 2,4,5,14,15 };
	int number = 10;
	
	int number2 = 4;

	int number3 = 21;

	std::cout << ClosestToZ(vec, number);
	std::cout << std::endl;
	std::cout << ClosestToZ(vec, number2);
	std::cout << std::endl;
	std::cout << ClosestToZ(vec, number3);
}