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
void get_len(ListNode* filter, int& length) {
    while (filter != NULL) {
        length++;
        filter = filter->next;
    }
}

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* filter = head;
        get_len(filter, len);

        for (int i = 0; i < len / 2; i++) {
            head = head->next;
        }

        return head;
    }
};