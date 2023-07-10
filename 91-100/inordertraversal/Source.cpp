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
void inordert(TreeNode* node, vector<int>& traversed) {

    if (node == nullptr) return;

    // traverse to left, comeback, right node
    inordert(node->left, traversed);

    traversed.push_back(node->val);

    inordert(node->right, traversed);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversed;

        inordert(root, traversed);

        return traversed;
    }
};