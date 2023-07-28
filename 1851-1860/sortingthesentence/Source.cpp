// O(2n) time: copy characters + scanning array
// Beats 100% time, and 89% space

class Solution {
public:
    string sortSentence(string s) {
        // create a hash to store substrings with p as key
        // whereas p refers word[-1]/postiion
        unordered_map<int, string> map;
        int k = 0, n = 0, p; // n := number of words
        string word = "";
        while (k < s.length()) {
            char c = s[k];
            if (c == ' ') {
                p = s[k - 1] - '0';
                map[p] = word.substr(0, word.length() - 1); n++;
                word = "";
            }
            else
                word += c;
            k++;
        }
        n++; p = s[k - 1] - '0';
        map[p] = word.substr(0, word.length() - 1);
        string res = "";
        // concat from 1-nWords substrings
        for (int i = 1; i < n; i++) {
            res += map[i] + " ";
        }
        res += map[n];

        return res;
    }
};