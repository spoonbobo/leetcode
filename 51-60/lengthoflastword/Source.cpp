// Traverse from Left, maybe can optimise by traversing from right
class Solution {
public:
    int lengthOfLastWord(string s) {
        // trivial case
        if (s.length() == 1) return 1;

        int length = 0, i;
        char prev;

        for (i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                if (prev == ' ' && i != 0)
                    length = 0;

                length++;
            }
            prev = s[i];
        }

        return length;
    }
};