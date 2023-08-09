// recursive solution, beats 90% time and 43% space

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

bool solver(TreeNode* root, int accum, int& targetSum) {
    if (root == nullptr)
        return false;
    if (root->left == nullptr && root->right == nullptr && accum == targetSum)
        return true;

    bool leftexist = false, rightexist = false;
    if (root->left != nullptr)
        leftexist = solver(root->left, accum + root->left->val, targetSum);
    if (root->right != nullptr)
        rightexist = solver(root->right, accum + root->right->val, targetSum);
    return leftexist || rightexist;
}

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return solver(root, root->val, targetSum);
    }
};