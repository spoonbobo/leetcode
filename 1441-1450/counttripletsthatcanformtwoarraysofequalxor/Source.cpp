/*
for any sub array A [i, k] with a size > 2,
if one satisfies A[i]^A[i+1]^...^A[j-1]^A[j]^A[j+1]^... ^A[k] = 0 (^=XOR)
Then A[i]^...A[j-1] AND A[j]^...^A[k] must be EQUAL based on XOR property <- learnt
Given i<j<=k, we are select any j in range of [i+1, k] to satisfy A[i:j] == A[j:k]
*/

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int res = 0, i, k, tmp, n = arr.size();
        for (i = 0; i < n - 1; i++) {
            tmp = arr[i];
            for (k = i + 1; k < n; k++) {
                tmp ^= arr[k];
                if (tmp == 0)
                    res += k - i;
            }
        }
        return res;
    }
};