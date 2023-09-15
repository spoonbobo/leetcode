// Improved over source.cpp: observed that if a single digit x is smaller than 10
// then x - digitsum(x) must be equal to 0, which must contribute 0 to the final answer
// beats 93% time

// get a single-digit sum
int get_sdigit_sum(const int& x) {
    string digitstr = to_string(x);
    int sdigit_sum = 0;
    for (auto& c : digitstr)
        sdigit_sum += c - '0';
    return sdigit_sum;
}

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int res = 0;
        for (auto& n : nums) {
            if (n > 9)
                res += abs(n - get_sdigit_sum(n));
        }
        return res;
    }
};