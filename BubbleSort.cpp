#include<iostream>
#include<vector>

//ð������
void BubbleSort(std::vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//��ӡ�ź���������
void PrintArr(std::vector<int>& arr) {
	for (auto& a : arr) {
		std::cout << a << " ";
	}
	std::cout << std::endl;

}

int main()
{
	std::vector<int> nums;
	nums = { 9,1,10,6,32,11,0,34,22,18 };
	BubbleSort(nums);
	PrintArr(nums);

	return 0;
}