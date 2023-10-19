// O(n) solution

string cvt(string& w, vector<string>& table) {
    string tmp = "";
    for (auto& c : w)
        tmp += table[c - 'a'];
    return tmp;
}

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> table{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        set<string> s;
        for (auto& w : words)
            s.insert(cvt(w, table));
        return s.size();
    }
};