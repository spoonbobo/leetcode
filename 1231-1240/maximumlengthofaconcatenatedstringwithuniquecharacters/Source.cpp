// this code seems to work, but TLE. have to optimize the backtracking.

int checkdup(string& s) {
    unordered_map<int, int> m;
    for (auto& e : s) {
        m[e]++;
        if (m[e] == 2) {
            return false;
        }
    }
    return true;
}

void bt(vector<string>& arr, int left, int& ans, int& n, string temp) {
    if (!checkdup(temp))
        return;

    if (temp.length() > ans)
        ans = temp.length();

    string bt_str;

    for (int i = left; i < n; i++) {
        bt_str = temp;
        temp += arr[i];
        bt(arr, left + 1, ans, n, temp);
        temp = bt_str;
    }
}

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans, n;
        ans = 0;
        n = arr.size();

        bt(arr, 0, ans, n, "");
        return ans;
    }
};