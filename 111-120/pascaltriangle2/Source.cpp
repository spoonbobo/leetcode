// dp solution, beats 100% time eand 99% space

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0)
            return vector<int>{1};
        if (rowIndex == 1)
            return vector<int>{1, 1};
        vector<int> res{1, 1};
        for (int i = 2; i < rowIndex + 1; i++) {
            int prev, temp;
            for (int e = 1; e < i; e++) {
                if (e == 1) {
                    prev = res[e];
                    res[e] = 1 + res[e];
                }
                else if (e == rowIndex - 1) {
                    res[e] = prev + 1;
                }
                else {
                    temp = res[e];
                    res[e] = prev + res[e];
                    prev = temp;
                }
            }
            res.push_back(1);
        }
        return res;
    }
};