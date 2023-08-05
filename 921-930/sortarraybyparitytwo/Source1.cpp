// I call it rolling sort Lol, O(n) time, O(1) space, two pointers.
// beats 99% time 

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        short int i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] % 2 == 1 && nums[j] % 2 == 0) {
                swap(nums[i], nums[j]);
            }
            else if (nums[i] % 2 == 1) {
                j += 2;
                continue;
            }
            else if (nums[j] % 2 == 0) {
                i += 2;
                continue;
            }
            i += 2; j += 2;
        }
        return nums;
    }
};