// backtracking solution, time complexity is O(n^3)

void bt(int left, int height, string tmp, vector<string>& res, vector<vector<char>>& vd) {
    if (tmp.length() == height) {
        res.push_back(tmp);
        return;
    }

    int tmpd;

    for (int i = 0; i < vd[left].size(); i++) {
        tmpd = tmp[left];
        tmp[left] = vd[left][i];
        bt(left + 1, height + 1, tmp, res, vd);
        tmp[left] = tmpd;
    }
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        // backtracking
        vector<vector<char>> vd;
        vector<string> res;
        int offset, _3or4, findchar;

        // init 
        for (auto& d : digits) {
            offset = (int)(d - '0');
            _3or4 = offset != 9 && offset != 7 ? 3 : 4;
            if (offset < 8)
                findchar = 91;
            else
                findchar = 92;

            vector<char> v;
            for (int i = 0; i < _3or4; i++)
                v.push_back((char)(offset * 3 + findchar + i));
            vd.push_back(v);
        }

        // backtracking code
        string tmp = "";
        // init tmp
        for (int i = 0; i < digits.length(); i++)
            tmp += ".";

        if (tmp.length() > 0)
            bt(0, 0, tmp, res, vd);
        return res;

    }
};