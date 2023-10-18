// O(n) time, O(1) space solution
// beats 100% time and only 6% space

class Solution {
public:
    bool checkIfPangram(string sentence) {
        int res = 0;
        unordered_map<char, int> m;
        for (auto& c : sentence) {
            if (m[c] == 0) {
                res++;
                m[c]++;
            }
        }
        return res == 26;
    }
};