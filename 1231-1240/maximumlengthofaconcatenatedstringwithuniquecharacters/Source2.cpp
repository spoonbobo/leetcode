// tried pass Hash Map by reference, also not working. May need to consider other algorithms.

void bt(
    vector<string>& arr, int left, int& ans, string curr_str, unordered_map<int, int>& ctr, const int& n) {

    int i, j, k;
    bool dup;
    string tmp_str, concat;

    if (curr_str.length() > ans)
        ans = curr_str.length();

    for (i = left; i < n; i++) {
        // printhm(ctr);
        tmp_str = curr_str;
        concat = arr[i];
        dup = false;

        for (j = 0; j < concat.length(); j++) {
            // cout << concat[j] << ":" << ctr[concat[j]] << endl;
            ctr[concat[j]]++;
            if (ctr[concat[j]] > 1) {
                dup = true;
                break;
            }
        }

        if (dup) {
            for (k = 0; k < j + 1; k++) {
                ctr[concat[k]]--;
            }
            continue; // duplicated
        }
        curr_str += concat;
        // cout << curr_str << endl;
        bt(arr, left + 1, ans, curr_str, ctr, n);

        for (j = 0; j < concat.length(); j++) {
            ctr[concat[j]]--;
        }
        curr_str = tmp_str;
    }
}


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int ans, n;
        ans = 0; // each substring could have dup letters
        n = arr.size();
        unordered_map<int, int> ctr;
        bt(arr, 0, ans, "", ctr, n);

        return ans;
    }
};