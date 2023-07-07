// O(n)
// worst case is leading zero all the way which causes 2 scans of whole array
// that is scanning leading zeros + shifting all elements to right and insert 1 at index 0

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // plus one
        digits[digits.size() - 1] = (digits[digits.size() - 1] + 1) % 10;

        // best cases
        if (digits[digits.size() - 1] != 0)
            return digits;

        // if reach here, last digit must be 0 after plus 1
        bool leadzero = true;
        int r = digits.size() - 2;

        while (r >= 0) {
            if (leadzero)
                digits[r] = (digits[r] + 1) % 10;
            if (digits[r] % 10 != 0)
                return digits;
            r--;
        }

        // if reach here, insert 1 at beginning
        digits.insert(digits.begin(), 1);

        return digits;
    }
};