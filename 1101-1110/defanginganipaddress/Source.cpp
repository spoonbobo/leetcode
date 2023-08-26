// O(n) time, beats 100% time and 62% space

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for (char& c : address) {
            if (c != '.') res += c;
            else
                res += "[.]";
        }
        return res;
    }
};