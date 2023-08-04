// O(sort) time, easy one.

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        for (auto i = 0; i < target.size(); i++) {
            if (target[i] != arr[i])
                return false;
        }
        return true;
    }
};