class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for (auto& w : words) {
            bool match = true;
            if (w.length() < pref.length())
                continue;
            for (int i = 0; i < pref.length(); i++) {
                if (w[i] != pref[i]) {
                    match = false;
                    break;
                }
            }
            if (match)
                res++;
        }
        return res;
    }
};