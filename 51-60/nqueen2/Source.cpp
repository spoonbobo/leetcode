// duplicate of problem 51.

void printg(char* grid, int& n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << grid[i * n + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool is_valid(int x, int y, int& n, char* grid) {
    // no need to check row

    // vertical
    for (int row = 0; row < y; row++) {
        if (grid[row * n + x] == 'Q')
            return false;
    }
    // positive slope
    for (int row = y - 1, col = x + 1; row >= 0 && col < n; row--, col++) {
        // cout << "45 row: " << row << " col: " << col << endl;
        if (grid[row * n + col] == 'Q')
            return false;
    }

    // negative slope
    for (int row = y - 1, col = x - 1; row >= 0 && col >= 0; row--, col--) {
        // cout << "135 row: " << row << " col: " << col << endl;
        if (grid[row * n + col] == 'Q')
            return false;
    }

    // cout << endl;
    return true;
}

vector<string> convert(char* grid, int& n) {
    vector<string> res;
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if (grid[i * n + j] == 'Q') s += 'Q';
            else s += '.';
        }
        res.push_back(s);
    }
    return res;
}

void bt(int y, char* grid, int n, vector<vector<string>>& res) {

    // distinct configuration found
    if (y == n) {
        res.push_back(convert(grid, n));
        return;
    }

    for (int x = 0; x < n; x++) {
        // cout << "x: " << x << " y: " << y << endl;
        if (is_valid(x, y, n, grid)) {
            // change state 
            grid[y * n + x] = 'Q';

            // go 1 level deeper
            bt(y + 1, grid, n, res);

            // backtrack
            grid[y * n + x] = '.';
        }
    }
}

class Solution {
public:
    int totalNQueens(int n)
    {
        vector<vector<string>> res;
        // trivial case
        if (n == 1) {
            res.push_back(vector<string>{"Q"});
            return res.size();
        }
        // if grid is 2x2/ 3x3 there is not going to be a immortal queen
        if (n == 2 || n == 3)
            return res.size();

        char* grid = new char[n * n]; // problem size
        // initialize grid
        for (int i = 0; i < n * n; i++) {
            grid[i] = '.';
        }

        // solve by backtracking
        bt(0, grid, n, res);

        delete[] grid;

        return res.size();
    }
};