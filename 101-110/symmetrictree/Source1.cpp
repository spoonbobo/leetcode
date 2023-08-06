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

// somehow beats 100% time too, but this time we get height first instead of checking all siblings equal to null as base case

bool symmetric(vector<TreeNode* >& left_tn, vector<TreeNode* >& right_tn) {
    for (short int i = 0, j = right_tn.size() - 1; i < left_tn.size() && j >= 0; i++, j--) {
        if (right_tn[i]->val == -150 && left_tn[j]->val != -150)
            return false;
        if (right_tn[i]->val != -150 && left_tn[j]->val == -150)
            return false;
        if (right_tn[i]->val != left_tn[j]->val) {
            return false;
        }
    }
    return true;
}

bool check(vector<TreeNode* >& left_tn, vector<TreeNode* >& right_tn, short int& height, short int& depth) {
    if (height == depth)
        return true;
    if (!symmetric(left_tn, right_tn))
        return false;

    vector<TreeNode* > new_left;
    for (short int i = 0; i < left_tn.size(); i++) {
        if (left_tn[i]->val != -150) {
            if (left_tn[i]->left == nullptr)
                new_left.push_back(new TreeNode(-150));
            else
                new_left.push_back(left_tn[i]->left);
            if (left_tn[i]->right == nullptr)
                new_left.push_back(new TreeNode(-150));
            else
                new_left.push_back(left_tn[i]->right);
        }
    }

    vector<TreeNode* > new_right;
    for (short int i = 0; i < right_tn.size(); i++) {
        if (right_tn[i]->val != -150) {
            if (right_tn[i]->left == nullptr)
                new_right.push_back(new TreeNode(-150));
            else
                new_right.push_back(right_tn[i]->left);
            if (right_tn[i]->right == nullptr)
                new_right.push_back(new TreeNode(-150));
            else
                new_right.push_back(right_tn[i]->right);
        }
    }
    height++;
    return check(new_left, new_right, height, depth);
}

short int getHeight(TreeNode* root) {
    if (root == nullptr)
        return 0;
    short int leftHeight = getHeight(root->left);
    short int rightHeight = getHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode* > left;
        vector<TreeNode* > right;
        if (root->left == nullptr)
            left.push_back(new TreeNode(-150));
        else
            left.push_back(root->left);
        if (root->right == nullptr)
            right.push_back(new TreeNode(-150));
        else
            right.push_back(root->right);
        short int depth = getHeight(root);
        short int height = 1;
        return check(left, right, height, depth);
    }
};