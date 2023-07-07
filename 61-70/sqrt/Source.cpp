// Bs O(n) time
int descent(int l, int r, int target) {

    if (l <= r) {
        long int mid = l + (r - l) / 2;
        if (mid * mid == target) return mid; // best case

        // another good case
        if ((mid * mid) < target && ((mid + 1) * (mid + 1) > target)) return mid;

        if (mid * mid > target)
            return descent(l, mid - 1, target);

        return descent(mid + 1, r, target);
    }
    return -1;
}

class Solution {
public:
    int mySqrt(int x) {
        // some trivial casess..
        if (x == 0) return 0;
        else if (x >= 1 && x <= 3) return 1;

        int ans = descent(0, x / 2, x);

        return ans;
    }
};