// this solution seems to very slow..

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m + n, 0);
        int i = 0, j = 0, k = 0;

        while ((i < m) && (j < n)) {
            if (nums1[i] < nums2[j]) {
                res[k] = nums1[i];
                i++;
            }
            else {
                res[k] = nums2[j];
                j++;
            }
            k++;
        }

        while ((i < m)) {
            res[k] = nums1[i];
            i++; k++;
        }

        while ((j < n)) {
            res[k] = nums2[j];
            j++; k++;
        }

        nums1 = res;

    }
};