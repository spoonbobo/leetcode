// preorder traversal solution, beats 85% time and 77% time 

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
void preorder(TreeNode* root, int& sum, int& low, int& high) {
    if (root == nullptr) return;

    if (root->val >= low && root->val <= high)
        sum += root->val;

    preorder(root->left, sum, low, high);
    preorder(root->right, sum, low, high);
}

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        preorder(root, sum, low, high);
        return sum;
    }
};