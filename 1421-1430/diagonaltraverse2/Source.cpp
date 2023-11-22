// Breath first search solution, used O(n) time and space.
// Beats 83% time and 70% space

struct Node {
    int x;
    int y;
    Node(int x, int y) : x(x), y(y) {}
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if (nums.size() == 1 && nums[0].size() == 1)
            return vector<int>{nums[0][0]};
        vector<int> res;
        queue<Node*> q;
        int n = nums.size();
        Node* root = new Node(0, 0);
        Node* tmp;
        q.push(root);
        while (!q.empty()) {
            tmp = q.front();
            res.push_back(nums[tmp->y][tmp->x]);
            q.pop();

            // add below child
            if (tmp->y + 1 < n && tmp->x == 0)
                q.push(new Node(tmp->x, tmp->y + 1));

            // add right child
            if (tmp->x + 1 < nums[tmp->y].size())
                q.push(new Node(tmp->x + 1, tmp->y));
        }
        return res;
    }
};