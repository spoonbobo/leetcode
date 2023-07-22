// Also O(n) solution, this is faster
// also learnt some usage of unordered map through this example

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, bool> seen;
        int ans = 0;
        for (auto word : words) {
            string w = word;
            reverse(w.begin(), w.end());
            if (seen[w])
                ans++;
            else
                seen[word] = true;
        }
        return ans;
    }
};