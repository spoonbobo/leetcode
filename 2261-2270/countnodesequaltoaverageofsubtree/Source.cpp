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

 // O(n^2): for each node, cal node sum and get its average
 // Used preorder traversal

int nodesum(TreeNode* root, int& traversed) {
    if (root == NULL)
        return 0;
    traversed++;
    return root->val + nodesum(root->left, traversed) + nodesum(root->right, traversed);
}

void preorder(TreeNode* root, int& ct) {
    if (root != NULL) {
        int traversed = 0, ns;
        ns = nodesum(root, traversed);
        if (ns / traversed == root->val)
            ct++;
        preorder(root->left, ct);
        preorder(root->right, ct);
    }
}

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ct = 0; // nodes equal to average of subtree
        preorder(root, ct);
        return ct;
    }
};