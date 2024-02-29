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

// BFS solution with queue. beats 86.55% of time and 89.27% of space

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode* > layer_nodes;
        TreeNode* tmp;
        layer_nodes.push(root);
        bool even_layer = true;

        // loop until there is no child for travelling layer.
        while (layer_nodes.size()) {
            int layer_size = layer_nodes.size(); // determine how many children are at this lyaer
            int prev_val = NULL; // used for checking sorted state of children at this layer
            for (int i = 0; i < layer_size; i++) {
                tmp = layer_nodes.front();
                
                // check odd&even validity of a child
                if ((even_layer && tmp->val % 2 == 0) || (!even_layer && tmp->val % 2 == 1))
                    return false;

                // check sorting validty of a child
                if (prev_val != NULL) {
                    if (even_layer && tmp->val <= prev_val) {
                        return false;
                    }
                    if (!even_layer && tmp->val >= prev_val) {
                        return false;
                    }
                }
                prev_val = tmp->val;

                // append the children to the queues
                if (tmp->left != nullptr)
                    layer_nodes.push(tmp->left);
                if (tmp->right != nullptr)
                    layer_nodes.push(tmp->right);

                // finished travelling of 1 node
                layer_nodes.pop();
            }

            // flip even_layer property to help determine nodes at next layer
            even_layer = even_layer ? false : true;
        }
        return true;
    }
};