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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int pos = 0;
        ListNode* filter = list1;
        ListNode* filter_p = nullptr;
        int rm_ct = 0;
        while (filter != NULL) {
            if (pos + 1 == a) {
                filter_p = new ListNode(filter->val, filter->next);
                //remove a-b+1 elements from filter
                while (rm_ct != b - a + 2) {
                    filter_p = filter_p->next;
                    rm_ct++;
                }
                filter->next = list2;
                // traverse all list2
                while (true) {
                    if (filter->next == nullptr)
                        break;
                    filter = filter->next;
                }
                filter->next = filter_p;
                // finish
                break;
            }
            else
                filter = filter->next;
            pos++;
        }
        return list1;
    }
};