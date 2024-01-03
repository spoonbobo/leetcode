class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res; int i; string tmp;
        for (i = 0; i < words.size(); i++) {
            tmp = words[i];
            if (find(tmp.begin(), tmp.end(), x) != tmp.end()) {
                res.push_back(i);
            }
        }
        return res;
    }
};