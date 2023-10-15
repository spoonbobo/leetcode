// O(n) implementation

class Solution {
public:
    string truncateSentence(string s, int k) {
        int ct = k, i;
        for (i = 0; ct > 0 && i < s.length(); i++) {
            if (s[i] == ' ')
                ct--;
        }
        if (i < s.length())
            return s.substr(0, i - 1);
        return s.substr(0, i);
    }
};