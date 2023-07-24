// probably the easiest question in leetcode
// O(n) solution, beats 100% time and roughly 60% space

class Solution {
public:
    bool detectCapitalUse(string word) {
        // trivial case
        if (word.length() == 1) return true;
        int tmp = (char)word[0];
        if (tmp <= 90) {
            if ((int)(char)word[1] <= 90) {
                // remaining must be CAPITALS
                for (int i = 2; i < word.length(); i++) {
                    if (word[i] > 90)
                        return false;
                }
            }
            else {
                // remaining must be lowercases
                for (int i = 2; i < word.length(); i++) {
                    if (word[i] <= 90)
                        return false;
                }
            }
        }
        else if (tmp > 90) {
            // remaining must be lowercases
            for (int i = 1; i < word.length(); i++) {
                if (word[i] <= 90)
                    return false;
            }
        }
        return true;
    }
};