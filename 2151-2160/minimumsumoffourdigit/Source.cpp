// An interesting O(1) solution, very greedy. 

class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        int p1, p2;
        sort(s.begin(), s.end());
        p1 = p1 * 10 + (s[0] - '0');
        p2 = p2 * 10 + (s[1] - '0');
        p1 = p1 * 10 + (s[2] - '0');
        p2 = p2 * 10 + (s[3] - '0');
        return p1 + p2;
    }
};