// O(n^2)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> seen;
        int k = nums.size();
        for (int i = 0, j = nums.size() - 1; i <= j; i++) {
            if (seen.find(nums[i]) != seen.end()) {
                k--; i--; j--;
                nums.erase(nums.begin() + i);
                nums.push_back(nums[i]);
            }
            seen.insert(nums[i]);
        }
        return k;
    }
};

// O(n) more elegant

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) count++;
            else nums[i - count] = nums[i];
        }
        return nums.size() - count;
    }
};