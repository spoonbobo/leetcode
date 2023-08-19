// recursive solution, beats 100% time

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
void invert(TreeNode* root) {
    if (root == nullptr)
        return;
    TreeNode* tmp = new TreeNode(root->val, root->left, root->right);
    root->left = tmp->right;
    root->right = tmp->left;
    invert(root->left);
    invert(root->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};