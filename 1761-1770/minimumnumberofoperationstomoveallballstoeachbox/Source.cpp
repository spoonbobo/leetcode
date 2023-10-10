// brute-force, O(n^2) solution, beats roughly 15% time and space

class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res;
        int tmp;
        for (int i = 0; i < boxes.size(); i++) {
            tmp = 0;
            for (int j = 0; j < boxes.size(); j++) {
                tmp += (boxes[j] - '0') * abs(j - i);
            }
            res.push_back(tmp);
        }
        return res;
    }
};