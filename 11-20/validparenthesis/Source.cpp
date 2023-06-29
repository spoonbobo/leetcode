class Solution {
public:
    bool isValid(string s) {
        vector<char> chars;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                chars.push_back(')');

            else if (s[i] == '{')
                chars.push_back('}');

            else if (s[i] == '[')
                chars.push_back(']');

            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                // must failure
                if ((chars.size() == 0) || (chars[chars.size() - 1] != s[i])) return false;

                chars.pop_back();
            }
        }

        if (chars.size() != 0)
            return false;

        return true;
    }
};