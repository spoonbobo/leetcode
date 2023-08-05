// dfs, O(n), O(h)

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
int dfs(stack<pair<TreeNode*, int>>& s, int max_depth) {
    // stack size
    if (s.size() == 0)
        return max_depth;

    // reach leaf
    if (s.top().first->left == nullptr && s.top().first->right == nullptr) {
        if (s.top().second > max_depth)
            max_depth = s.top().second;
    }

    pair<TreeNode*, int> top = s.top(); s.pop();

    if (top.first->left != nullptr)
        s.push(make_pair(top.first->left, top.second + 1));

    if (top.first->right != nullptr)
        s.push(make_pair(top.first->right, top.second + 1));

    return dfs(s, max_depth);
}

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        stack<pair<TreeNode*, int>> s;
        s.push(make_pair(root, 1));
        return dfs(s, 1);
    }
};