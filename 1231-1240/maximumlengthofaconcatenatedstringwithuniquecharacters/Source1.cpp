// Optimised form of source.cpp to reduce track process. However still TLE.

bool checkdup(string& s, unordered_map<int, int>& m) {
    for (auto& e : s) {
        m[e]++;
        if (m[e] == 2)
            return false; // cause duplication
    }
    return true;
}

void bt(vector<string>& arr, int left, int& ans, int& n, string curr_str, unordered_map<int, int> m)
{
    // update ans
    if (curr_str.length() > ans)
        ans = curr_str.length();

    string tmp;

    // search downward
    for (int i = left; i < n; i++) {
        tmp = curr_str;
        curr_str += arr[i];

        if (checkdup(arr[i], m)) // this modifies the hash map
            bt(arr, left + 1, ans, n, curr_str, m);

        // restore states
        for (int e = 0; e < arr[i].size(); e++)
            m[arr[i][e]]--;

        curr_str = tmp;
    }
}


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans, n;
        ans = 0; // each substring could have dup letters
        n = arr.size();
        unordered_map<int, int> ctr;

        bt(arr, 0, ans, n, "", ctr);

        return ans;
    }
};