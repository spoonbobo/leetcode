class Solution {
public:
    int percentageLetter(string s, char letter) {
        float occurence = 0.0f;
        float n = s.length();
        for (auto& c : s) {
            if (c == letter)
                occurence++;
        }
        return  (occurence * 100 / n);
    }
};