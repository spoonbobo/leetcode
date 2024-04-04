class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int ans = 0;
        for (auto& c : s) {
            if (c == '(')
                stk.push(c);
            else if (c == ')')
                stk.pop();
            ans = max(ans, (int)stk.size());
        }

        return ans;
    }
};