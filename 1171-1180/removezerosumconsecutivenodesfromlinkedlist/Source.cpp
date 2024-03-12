/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// first attempt to problem, failed


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m;
        ListNode* filter = head;
        int prefix_sum = 0;
        while (filter != nullptr) {
            prefix_sum += filter->val;
            if (m[prefix_sum]) {
                m[prefix_sum]->next = filter->next;
            }
            m[prefix_sum] = filter;
            filter = filter->next;
        }
        return head;
    }
};