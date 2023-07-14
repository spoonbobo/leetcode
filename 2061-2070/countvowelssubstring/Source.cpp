class Solution {
public:
    int countVowelSubstrings(string word) {
        // trivial case
            if (word.length() <= 4) return 0;

            int res = 0;
            vector<char> vowels;
            vowels.push_back('a');
            vowels.push_back('e');
            vowels.push_back('i');
            vowels.push_back('o');
            vowels.push_back('u');

            for (int i = 0; i < word.length(); i++) {
                if (find(vowels.begin(), vowels.end(), word[i]) == vowels.end()) {
                    continue;
                }
                set<int> seen;
                seen.insert(word[i]);

                for (int j = i + 1; j < word.length(); j++) {
                    if (find(vowels.begin(), vowels.end(), word[j]) == vowels.end()) {
                        break;
                    }
                    seen.insert(word[j]);
                    if (seen.size() == 5) res++;
                }
            }

            return res;
        }
    };