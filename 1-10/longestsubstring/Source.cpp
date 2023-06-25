#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // trivial cases;
        if ((nums1.size() == 1) && (nums1.size() == 0))
            return nums1[0];

        if ((nums1.size() == 0) && (nums1.size() == 1))
            return nums1[0];

        int i = 0, j = 0;
        double median = -1.0f;

        // allocate temp memory
        int n = nums1.size() + nums2.size();
        int* temp = new int[n];

        // merge 2 arrays
        while ((i < nums1.size()) && (j < nums2.size())) {
            if (nums1[i] < nums2[j]) {
                temp[i + j] = nums1[i];
                i++;
            }
            else {
                temp[i + j] = nums2[j];
                j++;
            }
        }

        // if remaining, add them into temp
        while (i < nums1.size()) {
            temp[i + j] = nums1[i];
            i++;
        }

        while (j < nums2.size()) {
            temp[i + j] = nums2[j];
            j++;
        }

        // check even or odd
        if (n % 2 == 0) // even
        {
            median = temp[n / 2] / (double)2 + temp[n / 2 - 1] / (double)2;
        }
        else
        {
            median = temp[n / 2];
        }

        return median;

    }
};