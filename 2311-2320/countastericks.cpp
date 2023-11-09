// O(n) time and O(1) space solution

class Solution {
public:
    int countAsterisks(string s) {
        bool v = true;
        int ans =0;
        for (auto& c: s) {
            if (c == '|') {
                v = v == true? false: true;
                continue;
            }
            if (c == '*' && v)
                ans++;
        }
        return ans;
    }
};