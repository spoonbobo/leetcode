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

// O(n) solution

int getdepth(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }
    else {
        int left = getdepth(node->left);
        int right = getdepth(node->right);
        return max(left, right) + 1;
    }
}

void dfs(TreeNode* root, int& ans, int level, int& depth) {
    if (level == depth && root != nullptr) {
        ans += root->val;
    }
    if (root != nullptr) {
        dfs(root->left, ans, level + 1, depth);
        dfs(root->right, ans, level + 1, depth);
    }
}

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth = getdepth(root);
        int ans = 0;
        dfs(root, ans, 1, depth);
        return ans;
    }
};