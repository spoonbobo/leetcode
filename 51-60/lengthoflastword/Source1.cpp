// I can think of we can save some spaces by not using prev
// but this problem is too simple, not worth of deep diving
class Solution {
public:
    int lengthOfLastWord(string s) {
        // trivial case
        if (s.length() == 1) return 1;

        int length = 0, i;
        char prev;

        for (i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ' ' && prev != ' ' && i != s.length() - 1) {
                return length;
            }
            if (s[i] != ' ')
                length++;

            prev = s[i];
        }

        return length;
    }
};