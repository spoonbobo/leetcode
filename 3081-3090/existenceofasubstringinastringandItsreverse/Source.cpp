class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string, int> m;
        string tmp;
        for (int i = 0; i < s.length() - 1; i++) {
            tmp = "";
            tmp += s[i];
            tmp += s[i + 1];
            m[tmp]++;
        }

        for (int i = s.length() - 1; i >= 1; i--) {
            tmp = "";
            tmp += s[i];
            tmp += s[i - 1];
            if (m[tmp])
                return true;
        }

        return false;
    }
};