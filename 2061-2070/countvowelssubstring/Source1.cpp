// Better than Source.cpp solution, it beats 60% time.
// Can be optimized further!
class Solution {
public:
    int countVowelSubstrings(string word) {
        // trivial case
        if (word.length() <= 4) return 0;

        int res = 0, i, j;
        unordered_map<char, int> counter;
        vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

        for (i = 0; i < word.length(); i++) {
            if (find(vowels.begin(), vowels.end(), word[i]) == vowels.end()) {
                continue;
            }
            counter.clear();
            counter[word[i]]++;

            for (j = i + 1; j < word.length(); j++) {
                if (find(vowels.begin(), vowels.end(), word[j]) == vowels.end()) break;
                counter[word[j]]++;
                if (counter.size() == 5) res++;
            }

            counter[word[i]]--;
            if (counter[word[i]] == 0)
                i = j;
        }

        return res;
    }
};