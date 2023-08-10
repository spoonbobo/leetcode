// O(sort) solution, beats 93% time 

class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        short int l, r;
        l = 0 + arr.size() * 0.05;
        r = arr.size() - arr.size() * 0.05;
        double f = (double)1 / (double)(r - l);
        double ans = 0;
        for (short int i = l; i < r; i++) {
            ans += arr[i] * f;
        }
        return ans;
    }
};