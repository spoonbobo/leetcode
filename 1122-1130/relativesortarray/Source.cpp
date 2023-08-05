// O(sort) solution.beats 100% time, 52.39% space

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // sort arr 1
        sort(arr1.begin(), arr1.end());

        // hashmap to count freq
        unordered_map<int, int> rec;
        for (int& num : arr1)
            rec[num]++;

        // restore res
        int k = 0;
        for (int& num : arr2) {
            for (int i = 0; i < rec[num]; i++, k++)
                arr1[k] = num;
            rec.erase(num);
        }

        // append left in rec to res
        vector<int> keys;

        for (auto& entry : rec) {
            keys.push_back(entry.first);
        }

        sort(keys.begin(), keys.end());

        for (int& num : keys) {
            for (int i = 0; i < rec[num]; i++, k++)
                arr1[k] = num;
        }

        return arr1;
    }
};