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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }
        else if (root1 != nullptr && root2 == nullptr) {
            return root1;
        }
        else if (root2 != nullptr && root1 == nullptr) {
            return root2;
        }
        TreeNode* newNode = new TreeNode(root1->val + root2->val);
        newNode->left = mergeTrees(root1->left, root2->left);
        newNode->right = mergeTrees(root1->right, root2->right);
        return newNode;
    }
};