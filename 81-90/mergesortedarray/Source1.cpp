// This solution beats 100% on time complexity.

void printvector(vector<int> nums) {
    for (auto i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";

    cout << endl;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int* la = new int[m];
        int* ra = new int[n];

        for (int i = 0; i < m; i++) {
            la[i] = nums1[i];
        }

        for (int j = 0; j < n; j++) {
            ra[j] = nums2[j];
        }

        int i = 0, j = 0, k = 0;

        while ((i < m) && (j < n)) {

            if (la[i] < ra[j]) {
                nums1[k] = la[i];
                i++;
            }
            else {
                nums1[k] = ra[j];
                j++;
            }
            k++;
        }

        while ((i < m)) {
            nums1[k] = la[i];
            i++; k++;
        }

        while ((j < n)) {
            nums1[k] = ra[j];
            j++; k++;
        }

        delete[] la, ra;
    }
};