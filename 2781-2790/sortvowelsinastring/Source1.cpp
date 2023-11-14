// slightly optimized version of source.cpp by using sort instead of pq

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<char> vf;

        for (int i = 0; i < s.length(); i++) {
            if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) {
                vf.push_back(s[i]);
                s[i] = ' ';
            }
        }

        sort(vf.begin(), vf.end());

        int c = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s[i] = vf[c];
                c++;
            }
        }

        return s;
    }
};