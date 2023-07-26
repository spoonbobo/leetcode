// Backtracking. Beats 100% time (O(solutionSpace)) and 87% space (O(n))
// The reason why it's so fast is because it pruned most subtrees that do not contain solution

void bt(string s, string traversed, int start, int dist, int depth, vector<string>& res) {
    if (traversed.length() == s.length() + 3) {
        res.push_back(traversed);
        return;
    }

    if (dist + ((4 - depth) * 3) < s.length())
        return;

    string cand; int candint;

    for (int len = 1; len <= 3 && start + len < s.length() + 1; len++) {
        cand = s.substr(start, len);
        candint = stoi(cand);
        if (!(cand.length() > 1 && cand[0] == '0') && candint >= 0 && candint <= 255) {
            string tmp = traversed;
            if (dist == 0)
                traversed += cand;
            else
                traversed += "." + cand;
            bt(s, traversed, start + len, dist + len, depth + 1, res);
            traversed = tmp;
        }
    }
}

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // solve by backtracking.
        vector<string> res;
        bt(s, "", 0, 0, 0, res);
        return res;
    }
};