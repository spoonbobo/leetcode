// DFS slight speed improved, beat 98%

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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int leftHeight, rightHeight;
        if (root->left != nullptr)
            leftHeight = minDepth(root->left);
        else
            leftHeight = INT_MAX;

        if (root->right != nullptr)
            rightHeight = minDepth(root->right);
        else
            rightHeight = INT_MAX;

        return min(leftHeight, rightHeight) + 1;
    }
};