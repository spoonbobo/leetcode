// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int bs(int n, int l, int r) {
    int mid;
    if (l <= r) {
        mid = l + (r - l) / 2;
        // found a bad
        if (isBadVersion(mid)) {
            while ((mid - 1) > 0) {
                if (isBadVersion(mid - 1) == false)
                    return mid;
                mid--;
            }
            return mid;
        }

        else {
            return bs(n, mid + 1, r);
        }
    }
    return -1;
}

class Solution {
public:
    int firstBadVersion(int n) {
        // trivial case
        if (n == 1) return 1;

        return bs(n, 1, n);
    }
};