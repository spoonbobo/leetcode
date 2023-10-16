// O(s1Length+s2Length) time and space solution

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1 = "", s2 = "";
        for (auto& c : word1)
            s1 += c;
        for (auto& c : word2)
            s2 += c;
        return s1 == s2;
    }
};