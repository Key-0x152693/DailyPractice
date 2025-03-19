#include<iostream>
#include<vector>

void SelectionSort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; ++i) {
		int minNum = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minNum]) {
				minNum = j;
			}
		}
		if (minNum != i) {
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

int main() {
	std::vector<int> nums;
	nums = { 9,1,10,6,32,11,0,34,22,18 ,-7,-21 };
	PrintArr(nums);
	SelectionSort(nums);
	PrintArr(nums);
	return 0;
}