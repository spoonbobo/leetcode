// O(key+message) time and O(1) solution
// Beats 100% time and only 22% space

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> map;
        string res = "";
        char encode = 'a';
        map[' '] = ' ';
        for (char& c : key) {
            if (map[c] == 0 && c != ' ') {
                map[c] = encode;
                encode++;
            }
        }
        for (auto& c : message) {
            res += map[c];
        }
        return res;
    }
};