// O(n) time and O(1) space solution
// beats 100% time and 60% space

class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        int ptr = 'a';
        for (auto& c : word) {
            ans += min(abs(c - ptr), c < ptr ? abs(c + 26 - ptr) : abs(ptr + 26 - c));
            ptr = c;
            ans++;
        }
        return ans;
    }
};