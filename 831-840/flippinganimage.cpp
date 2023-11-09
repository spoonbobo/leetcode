// O(n^2) solution, beats 82% time and 80% space
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        // flipping
        int m,n;
        m = image.size();
        n = image[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n/2; j++) {
                swap(image[i][j], image[i][n-j-1]);
            }
        }
        // inverting
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                image[i][j] ^= 1;
            }
        }

        return image;
    }
};