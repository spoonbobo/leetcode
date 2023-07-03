/*
This version is better than Source1.cpp because it not only prunes the tree for traversed idx
But also prune the trees if it found an idx (sorted candidates) that causes traversed_sum+this_idx > target, it will prune all idxs after that
*/

#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> traversed, int current_idx, int traverse_sum) {
    // 2 cases
    // if traverse sum < target, continue traversing if satisfies both constraints

    /*
        Constraints:
            1) sum+child < target;
            2) sum+child not appeared in result set
    */

    // if traverse sum == target, add to result list
    // printvector(traversed);

    if (traverse_sum == target) {
        result.push_back(traversed);
        return;
    }

    for (int i = current_idx; i < candidates.size(); i++) {
        if (traverse_sum + candidates[i] > target)
            break;
        traversed.push_back(candidates[i]);
        backtracking(candidates, target, result, traversed, i, traverse_sum + candidates[i]);
        traversed.pop_back();
    }
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        // trivial cases
        if (candidates.size() == 1) {
            if (candidates[0] == target) {
                vector<int>temp{candidates[0]};
                result.push_back(temp);
            }
            return result;
        }

        vector<int> traversed;
        sort(candidates.begin(), candidates.end());

        backtracking(candidates, target, result, traversed, 0, 0);

        return result;
    }
};
