class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int max_i = 1, max_d, i, j;
        for (i = 0; i < arr.size() - 1; i++) {
            if (i > 0 && max_i > i) {
                arr[i] = arr[max_i];
                continue;
            }
            max_d = 0;
            for (j = max(max_i, i + 1); j < arr.size(); j++) {
                if (arr[j] > max_d) {
                    max_i = j;
                    max_d = arr[max_i];
                }
            }
            arr[i] = arr[max_i];
        }
        arr[arr.size() - 1] = -1;
        return arr;
    }
};