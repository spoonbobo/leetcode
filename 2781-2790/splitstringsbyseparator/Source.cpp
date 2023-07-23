// O(n) solution

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        string temp;

        for (string word : words) {
            for (char subword : word) {
                if (subword != separator)
                    temp += subword;
                else {
                    if (temp.length() > 0) {
                        res.push_back(temp);
                        temp = "";
                    }
                }
            }
            if (temp.length() > 0) {
                res.push_back(temp);
                temp = "";
            }
        }

        return res;
    }
};