// O(1) space, O(n) time solution

class Solution {
public:
    string interpret(string command) {
        string ans = "", tmp = "";
        unordered_map<string, string> m;
        m["G"] = "G"; m["()"] = "o"; m["(al)"] = "al";
        for (auto& c : command) {
            tmp += c;
            if (m[tmp] != "") {
                ans += m[tmp];
                tmp = "";
            }
        }
        return ans;

    }
};