// O(n) solution.

class Solution {
public:
    string toLowerCase(string s) {
        string res = "";
        for (auto& c: s) {
            if ((int)c >= 65 && (int)c <= 90) {
                res += (char)(c+32);
                continue;
            }
            res+=c;
        }
        return res;
    }
};