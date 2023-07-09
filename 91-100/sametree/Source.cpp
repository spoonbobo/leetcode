// Beats everything in time and space
// O(n) time O(1) space

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
void checkpreorder(TreeNode* p, TreeNode* q, bool& state) {

    if (state == true) {
        if (p == nullptr && q == nullptr)
            return;

        // failed case
        if (p == nullptr || q == nullptr || p->val != q->val) {
            state = false;
            return;
        }

        checkpreorder(p->left, q->left, state);
        checkpreorder(p->right, q->right, state);

    }
    else
        return;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // traverse p in preorder, if q does not follow, return false;
        bool ans = true;
        checkpreorder(p, q, ans);

        return ans;
    }
};