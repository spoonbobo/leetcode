// BFS, beats 97% time, but very space expensive

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
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, 1));

        while (q.size() != 0) {

            pair<TreeNode*, int> node = q.front();
            q.pop();
            if (node.first->left == nullptr && node.first->right == nullptr)
                return node.second;

            if (node.first->left != nullptr)
                q.push(make_pair(node.first->left, node.second + 1));

            if (node.first->right != nullptr)
                q.push(make_pair(node.first->right, node.second + 1));
        }

        return -1;
    }
};