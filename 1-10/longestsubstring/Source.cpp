#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

int getMax(int a, int b) { return (a > b) ? a : b; };

int lengthOfLongestSubstring(string s) {
    int n = s.length();

    if (n == 0) return 0;
    if (n == 1) return 1;

    // dynamic slide window
    int l;
    int max_length;
    unordered_map<char, int> seen;
    l = 0;  max_length =0;

    for (int r = 0; r < n ; r++) {
        // not seen at all
        if (seen.find(s[r]) == seen.end())
        {
            max_length = getMax(max_length, r - l + 1);
        }
        else
        {
            // if seen in slide window jump there
            if (seen[s[r]] < l)
                max_length = getMax(max_length, r - l + 1);
            else
                l = seen[s[r]] + 1;
            }
        seen[s[r]] = r;
    }
    return max_length;
}

int main() {
    string s = "abba";

    int longestSubstring = lengthOfLongestSubstring(s);

    cout << longestSubstring << endl;
    return 0;
}