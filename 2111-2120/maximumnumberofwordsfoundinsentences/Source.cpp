// O(n) solution

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int max_n = 0, word; // from constraint
        for (auto& s : sentences) {
            word = 0;
            for (auto& c : s) {
                if (c == ' ')
                    word++;
            }
            if (word > max_n)
                max_n = word;
        }
        return max_n + 1;
    }
};