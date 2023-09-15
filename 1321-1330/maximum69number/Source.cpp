// best case O(1) worst case O(n) solution, beats 100% time

class Solution {
public:
    int maximum69Number(int num) {
        // swap first 6 and first 9 after it
        string numstr = to_string(num);
        for (int i = 0; i < numstr.size(); i++) {
            if (numstr[i] == '6') {
                numstr[i] = '9'; break;
            }
        }
        return stoi(numstr);
    }
};