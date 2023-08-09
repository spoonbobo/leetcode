// O(n), can be optimized

class Solution {
public:
    bool isPalindrome(string s) {
        int i, j;
        // removing non-alpha
        string s2 = "";
        int val;
        for (char& c : s) {
            val = (int)c;
            if (val >= 97 && val <= 122 || val >= 48 && val <= 57)
                s2 += c;
            else if (val >= 65 && val <= 90) {
                s2 += (char)val + 32;
            }
        }

        i = 0, j = s2.length() - 1;
        if (s2.length() == 0)
            return true;

        // if (s2.length() == 1)
        //     return false;

        while (true) {
            if (i > j)
                break;
            if (s2[i] != s2[j])
                return false;
            i++;
            j--;
        }


        return true;
    }
};
