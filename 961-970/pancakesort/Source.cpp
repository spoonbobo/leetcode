int findmax(vector<int>& arr, int n) {
    int max_i, currmax = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > currmax) {
            max_i = i;
            currmax = arr[i];
        }
    }
    return max_i;
}

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> flips;
        int k;
        for (int flip = 0; flip < arr.size() - 1; flip++) {
            k = findmax(arr, arr.size() - flip);
            reverse(arr.begin(), arr.begin() + k + 1);
            flips.push_back(k + 1);
            reverse(arr.begin(), arr.begin() + arr[0]);
            flips.push_back(arr[arr.size() - flip - 1]);
        }

        return flips;
    }
};