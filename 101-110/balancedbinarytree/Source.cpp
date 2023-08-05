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

// see ./idea.png to illustrate the (sub)problem

int getHeight(TreeNode* root) {
    // solving a subproblem: asking left or right is higher
    if (root == nullptr) return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};