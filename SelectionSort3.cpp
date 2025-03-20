#include<iostream>
#include<vector>

void Sort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		int minNum = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minNum]) {
				minNum = j;
			}
		}
		if (i != minNum) {
			std::swap(arr[i], arr[minNum]);
		}
	}
}

void PrintArr(std::vector<int>& arr) {
	for (auto& a : arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> nums = { 1,4,-5,65,11,-89,12,3,16 };

	Sort(nums);

	PrintArr(nums);

	return 0;
}