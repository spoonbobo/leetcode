// O(1) solution

class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (coordinates[0] + (coordinates[1] - '0')) % 2;
    }
};