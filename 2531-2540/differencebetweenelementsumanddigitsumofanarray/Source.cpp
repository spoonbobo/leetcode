// O(n*avg(singitLen)) solution, beats roughly 20% time and space, seem can be optimized

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
        int elem_sum = 0, digit_sum = 0;
        for (auto& n : nums) {
            elem_sum += n;
            digit_sum += get_sdigit_sum(n);
        }
        return abs(elem_sum - digit_sum);
    }
};