// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// Source.cpp implementation is O (nlogn) which is sucks.
// this implements O(n) time.

int bs(int n, int l, int r) {
    int mid;
    if (l <= r) {
        mid = l + (r - l) / 2;
        if (isBadVersion(mid) && !isBadVersion(mid - 1))
            return mid;

        if (isBadVersion(mid))
            return bs(n, l, mid - 1);

        return bs(n, mid + 1, r);
    }
    return 1;
}

class Solution {
public:
    int firstBadVersion(int n) {
        // trivial case
        if (n == 1) return 1;

        return bs(n, 1, n);
    }
};