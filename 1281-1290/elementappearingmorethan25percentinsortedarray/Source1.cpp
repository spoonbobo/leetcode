// O(n) time & O(1) space

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int curr, ct;
        curr = arr[0]; ct = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] != curr) {
                curr = arr[i]; ct = 0;
            }
            ct++;
            if (ct > arr.size() * 0.25)
                return curr;
        }
        return curr;
    }
};