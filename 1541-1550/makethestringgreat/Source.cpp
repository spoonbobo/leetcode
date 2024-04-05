class Solution {
public:
    string makeGood(string s) {
        bool badstr = true;
        while (badstr) {
            string tmp = "";
            badstr = false;
            for (int i = 0; i < s.length(); i++) {
                if (i == s.length() - 1) {
                    tmp += s[i];
                    break;
                }
                if (abs(s[i + 1] - s[i]) == 32) {
                    badstr = true;
                    i++;
                }
                else
                    tmp += s[i];
            }
            cout << tmp << endl;
            s = tmp;
        }
        return s;
    }
};