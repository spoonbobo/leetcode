class Solution {
public:
    int totalMoney(int n) {
        int arr[7] = { 1,2,3,4,5,6,7 };
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += arr[i % 7]++;
        }
        return ans;
    }
};