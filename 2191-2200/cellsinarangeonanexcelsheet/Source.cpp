// O(r*c) solution

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res; string tmp = "";
        int width, height;
        width = s[3] - s[0];
        height = s[4] - s[1];
        for (int c = s[0]; c <= s[0] + width; c++) {
            for (int r = s[1]; r <= s[1] + height; r++) {
                tmp += (char)c;
                tmp += (char)r;
                res.push_back(tmp);
                tmp = "";
            }
        }
        return res;
    }
};