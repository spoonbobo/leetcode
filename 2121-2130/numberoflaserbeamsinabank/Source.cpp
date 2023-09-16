// O(m*n) solution

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int beams = 0, last_beam_sum = 0, new_beam_sum;
        for (auto& b : bank) {
            new_beam_sum = 0;
            for (auto& c : b)
                new_beam_sum += c - '0';
            // if new_beam_sum is 0, continue and use last_beam_sum
            if (new_beam_sum) {
                // beams at r>0: last_beam_sum*new_beam_sum
                // when i=0, 0*new_beam_sum = 0, so no beams will be added for first row

                // this question allows 2 js to have beam
                // in a case that it does not allow to do that, just subtract - new_beam_sum to exclude
                beams += new_beam_sum * last_beam_sum;
                last_beam_sum = new_beam_sum;
            }
        }
        return beams;
    }
};