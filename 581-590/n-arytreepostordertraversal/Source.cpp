/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

void porder(Node* root, vector<int>& res) {
    if (root != NULL) {
        for (auto& child : root->children)
            porder(child, res);
        res.push_back(root->val);
    }
}

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        porder(root, res);
        return res;
    }
};