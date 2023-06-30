void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // trivial cases
        if (nums.size() == 1 && nums[0] == val) return 0;

        int k = nums.size();

        for (int i = 0, j = nums.size() - 1; i <= j; i++) {
            if (nums[i] == val) {
                k--;
                // determine swap
                while (nums[j] == val && j > 0 && i != j) {
                    j--;
                    k--;
                }
                swap(nums[i], nums[j]);
                if (j > 0)
                    j--;
            }
        }

        return k;
    }
};