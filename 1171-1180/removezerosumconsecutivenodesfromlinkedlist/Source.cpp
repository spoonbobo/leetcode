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


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> m;
        ListNode* filter = head;
        int prefix_sum = 0, tmp_sum;
        while (filter != nullptr) {
            prefix_sum += filter->val;
            if (prefix_sum == 0) {
                head = filter->next;
                m.clear();
            }
            if (m[prefix_sum]) {
                ListNode* filter2 = m[prefix_sum];
                tmp_sum = prefix_sum;
                // eliminate until next node 
                while (true) {
                    tmp_sum += filter2->next->val;
                    if (tmp_sum == prefix_sum) {
                        m[prefix_sum]->next = filter->next;
                        break;
                    }
                    m[tmp_sum] = 0;
                    filter2 = filter2->next;
                }

            }
            else
                m[prefix_sum] = filter;

            filter = filter->next;
        }

        if (!prefix_sum)
            return nullptr;

        return head;
    }
};