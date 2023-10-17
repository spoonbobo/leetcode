// O(n^3) solution, beats 100% time, only 35% space

class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int i, j, k, n, res;
        i = 0; n = nums.size(); res = 0;
        while (i < n - 2) {
            j = i + 1;
            while (j < n - 1) {
                if (nums[j] - nums[i] > diff)
                    break;
                if (nums[j] - nums[i] == diff) {
                    k = j + 1;
                    while (k < n) {
                        if (nums[k] - nums[j] > diff)
                            break;
                        if (nums[k] - nums[j] == diff) {
                            res++;
                            break;
                        }
                        k++;
                    }
                }
                j++;
            }
            i++;
        }
        return res;
    }
};