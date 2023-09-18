// solve by binary search O(logn), beats 100% time, but leetcode suggested space could be optimized

// binary search
int arisum(const int& a, const int& n, const int& d) {
    return (float)n * ((float)2 * a + (float)(n - 1) * d) / (float)2;
}

int bs(int left, int right, const int& n) {
    int mid, leftsum, rightsum;
    while (true) {
        if (left > right)
            break;

        mid = (left + right) / 2;
        leftsum = arisum(1, mid, 1);
        rightsum = arisum(mid, (n - mid + 1), 1);

        // return condition: left accu sum is equal to right accu sum
        if (leftsum == rightsum)
            return mid;

        // if left is part is larger, mark right as mid-1
        else if (leftsum > rightsum)
            right = mid - 1;

        else
            left = mid + 1;

    }
    return -1;
}

class Solution {
public:
    int pivotInteger(int n) {
        return bs(1, n, n);
    }
};