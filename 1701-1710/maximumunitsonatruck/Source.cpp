// O(mergesort) solution
// very slow, needs to be optimized

void merge(vector<vector<int>>& boxTypes, int l, int m, int r) {
    vector<vector<int>> left_vec;
    vector<vector<int>> right_vec;
    for (int i = 0; i < m - l + 1; i++)
        left_vec.push_back(boxTypes[l + i]);

    for (int i = 0; i < r - m; i++)
        right_vec.push_back(boxTypes[m + 1 + i]);

    int i, j, k;
    k = l; i = 0; j = 0;

    while (i < left_vec.size() && j < right_vec.size()) {
        if (left_vec[i][1] > right_vec[j][1]) {
            boxTypes[k] = left_vec[i];
            i++;
        }
        else {
            boxTypes[k] = right_vec[j];
            j++;
        }

        k++;
    }

    while (i < left_vec.size()) {
        boxTypes[k] = left_vec[i];
        i++; k++;
    }

    while (j < right_vec.size()) {
        boxTypes[k] = right_vec[j];
        j++; k++;
    }

}

void mergeSort(vector<vector<int>>& boxTypes) {
    int mid, right, n = boxTypes.size();
    for (int sub_array_size = 1; sub_array_size < n; sub_array_size *= 2)
        for (int left = 0; left < n; left += 2 * sub_array_size) {
            mid = min(left + sub_array_size - 1, n - 1);
            right = min(left + 2 * sub_array_size - 1, n - 1);
            merge(boxTypes, left, mid, right);
        }
}

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort based on numUnits
        mergeSort(boxTypes);
        for (auto bt : boxTypes) {
            for (auto b : bt)
                cout << b << " ";
            cout << endl;
        }

        int res = 0, ptr = 0;
        while (truckSize != 0) {
            if (boxTypes[ptr][0] == 0)
                ptr++;
            if (ptr > boxTypes.size() - 1) break;
            res += boxTypes[ptr][1];
            boxTypes[ptr][0]--;
            truckSize--;
        }
        return res;
    }
};