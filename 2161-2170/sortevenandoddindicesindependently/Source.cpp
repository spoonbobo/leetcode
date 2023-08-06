// O(sort) 2 sort needed, and then change elements in place

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> oddi;
        vector<int> even;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) even.push_back(nums[i]);
            else oddi.push_back(nums[i]);
        }
        sort(oddi.begin(), oddi.end(), greater<>());
        sort(even.begin(), even.end());

        int i = 0;
        while (i < nums.size()) {
            if (i % 2 == 0)
                nums[i] = even[i / 2];
            else
                nums[i] = oddi[i / 2];
            i++;
        }
        return nums;
    }
};