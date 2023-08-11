// Optimized version of source.cpp, removed print statement......, beats 100% time and space

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int x, y;
        for (y=0; y<grid.size(); y++) {
            for (x=0; x<grid[0].size(); x++) {
                if (y==0 && x==0) 
                    continue;
                else if (y==0)
                    grid[y][x] = grid[y][x] + grid[y][x-1]; // first column
                else if (x==0)
                    grid[y][x] = grid[y][x] + grid[y-1][x]; // first row
                else
                    grid[y][x] = grid[y][x] + min(grid[y-1][x], grid[y][x-1]); // any other case
            }
        }
        return grid[y-1][x-1];
    }
};