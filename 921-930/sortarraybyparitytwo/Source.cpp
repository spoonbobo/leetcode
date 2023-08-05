// O(n) solution, but it takes so much space, can be optimized

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odds;
        vector<int> even;

        for (int& num : nums) {
            if (num % 2 == 0) even.push_back(num);
            else odds.push_back(num);
        }

        int k = 0;
        while (k < nums.size()) {
            if (k % 2 == 0)
                nums[k] = even[k / 2];
            else
                nums[k] = odds[k / 2];
            k++;
        }

        return nums;

    }
};