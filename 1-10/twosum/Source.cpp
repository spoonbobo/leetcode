#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void printVector(vector<int> res) {
	cout << "[";
	for (int i = 0; i < res.size(); i++) {
		if (i != res.size() - 1) cout << res[i] << ",";
		else cout << res[i];
	}
	cout << "]\n";
	cin.get();

}

vector<int> twoSum(vector<int>& nums, int target) {
	unordered_map<int, int> map;
	int complement;
	for (int i = 0; i < nums.size(); i++) {
		complement = target - nums[i];
		if (map.find(complement) != map.end()) return vector<int>{map[complement], i};
		map[nums[i]] = i;
	}
	return vector<int>{};
}

int main()
{
	vector<int> nums{ 0, 4, 3, 0 };
	vector<int> result;
	int target = 0;

	result = twoSum(nums, target);

	printVector(result);
}