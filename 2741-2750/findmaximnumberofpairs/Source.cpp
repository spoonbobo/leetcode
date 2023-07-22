// O(n) time/space solution, but seems can be optimized.
// beats 70% time, and 50% space

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        // O(n) space and time
        set<string> seen;
        string word;
        int ans = 0;
        for (int i = 0; i < words.size(); i++) {
            word = words[i];
            sort(word.begin(), word.end());
            if (find(seen.begin(), seen.end(), word) != seen.end())
                ans++;
            seen.insert(word);
        }
        return ans;
    }
};