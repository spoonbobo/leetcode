// O(sort) solution. beats 63% time and space

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> tmp(arr.begin(), arr.end());
        sort(tmp.begin(), tmp.end());
        unordered_map<int, int> map;

        for (int i = 0; i < tmp.size(); i++) {
            if (i > 0 && tmp[i] == tmp[i - 1])
                continue;
            map[tmp[i]] = map.size() + 1;
            cout << map.size() << endl;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = map[arr[i]];
        }
        return arr;

    }
};