// hash table to record found status for each depth
// beats 99% time and 40% space
// maybe can optimised by DFS, implement later

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
void findvalue(TreeNode* root, int curr_depth, int max_depth, unordered_map<int, int>& found, int& res) {
    if (root != nullptr) {
        if (!(found[curr_depth]) && curr_depth > max_depth) {
            found[curr_depth]++;
            max_depth = curr_depth;
            res = root->val;
        }
        findvalue(root->left, curr_depth + 1, max_depth, found, res);
        findvalue(root->right, curr_depth + 1, max_depth, found, res);
    }
}

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        unordered_map<int, int> found;
        findvalue(root, 0, 0, found, res);
        return res;
    }
};