// O(size(strs)*n)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // trivial casee
        if (strs.size() == 1) return strs[0];

        string ans = "";

        for (int char_idx = 0; char_idx < strs.size(); char_idx++) {
            char curr_char = strs[0][char_idx];
            for (int string_idx = 1; string_idx < strs.size(); string_idx++) {
                if (strs[string_idx][char_idx] != curr_char) return ans;
            }
            ans += curr_char;
        }

        return ans;
    }
};