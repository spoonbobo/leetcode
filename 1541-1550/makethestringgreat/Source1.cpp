class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for (auto& c : s) {
            if (!stk.empty() && abs(c - stk.top()) == 32) {
                stk.pop();
            }
            else
                stk.push(c);
        }
        string res(stk.size(), ' ');
        for (int i = stk.size() - 1; i >= 0; i--) {
            res[i] = stk.top();
            stk.pop();
        }
        return res;

    }
};