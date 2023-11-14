// O(nlogn) sort solution, O(n) space, can be optimized

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        priority_queue<char, vector<char>, greater<char>> pq;
        for (int i = 0; i < s.length(); i++) {
            if (find(vowels.begin(), vowels.end(), s[i]) != vowels.end()) {
                pq.push(s[i]);
                s[i] = ' ';
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                s[i] = pq.top();
                pq.pop();
            }
        }
        return s;
    }
};