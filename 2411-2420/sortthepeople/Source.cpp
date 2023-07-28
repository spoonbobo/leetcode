// O(sort) time complexity solution, beats 99.43% time.

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // hash table store key as height(int) , value -> names
        unordered_map<int, string> mapping;
        for (int i = 0; i < names.size(); i++)
            mapping[heights[i]] = names[i];

        // sort heights: [180, 165, 170] -> [165, 170, 180]
        sort(heights.begin(), heights.end());

        // create vector<string> list of strings
        // every element, hash_table[165], hash_table[170], hash_table[180]
        vector<string> res;
        for (int i = heights.size() - 1; i >= 0; i--) {
            res.push_back(mapping[heights[i]]);
        }

        return res;
    }
};