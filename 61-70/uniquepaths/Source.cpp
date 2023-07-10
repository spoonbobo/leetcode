bool isValid(int& y, int& x, int& m, int& n) {
    if (y < 0 || x < 0 || y > m || x > n)
        return false;
    return true;
}

void recur(int y, int x, int end_y, int end_x, int& res) {
    // travel outside grid
    if (!isValid(y, x, end_y, end_x)) {
        return;
    }
    // good end state
    if (y == end_y && x == end_x) {
        res++;
        return;
    }

    recur(y + 1, x, end_y, end_x, res);
    recur(y, x + 1, end_y, end_x, res);
}

class Solution {
public:
    int uniquePaths(int m, int n) {

        // trivial case
        if (m == 1 && n == 1)
            return 1;


        int res = 0;
        recur(0, 0, m - 1, n - 1, res);
        return res;
    }
};