void printvector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void backtracking(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int> traversed) {
    // 2 cases
    // if traverse sum < target, continue traversing if satisfies both constraints

    /*
        Constraints:
            1) sum+child < target;
            2) sum+child not appeared in result set
    */

    // if traverse sum == target, add to result list
    // printvector(traversed);

    int traverse_sum = accumulate(traversed.begin(), traversed.end(), 0);

    if (traverse_sum == target) {
        result.push_back(traversed);
    }

    vector<int> temp;

    for (int i = 0; i < candidates.size(); i++) {
        if ((traverse_sum + candidates[i]) <= target) {
            temp = traversed;
            temp.push_back(candidates[i]);
            sort(temp.begin(), temp.end());
            auto it = find(result.begin(), result.end(), temp);
            if (it == result.end())
                backtracking(candidates, target, result, temp);
        }
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

        backtracking(candidates, target, result, traversed);

        return result;
    }
};