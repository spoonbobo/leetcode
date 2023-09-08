// O(n) solution

class Solution {
public:
    int subtractProductAndSum(int n) {
        string tmp = to_string(n);
        int product = 1, sum = 0, decoded;
        for (auto& c : tmp) {
            decoded = c - '0';
            product *= decoded;
            sum += decoded;
        }
        return product - sum;
    }
};