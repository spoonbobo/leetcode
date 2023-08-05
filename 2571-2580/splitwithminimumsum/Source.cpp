// O(sort) solution, beats 100% time

class Solution {
public:
    int splitNum(int num) {
        string numS = to_string(num); int r;
        sort(numS.begin(), numS.end());
        string s1 = "", s2 = "";
        // 235
        for (int i = 0; i < numS.length(); i++) {
            if (i % 2 == 0)
                s1 += numS[i];
            else
                s2 += numS[i];
        }
        return stoi(s1) + stoi(s2);
    }
};