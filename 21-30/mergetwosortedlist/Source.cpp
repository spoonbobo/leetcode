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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // trivial cases
        if ((list1 == NULL) && (list2 == NULL))
            return NULL;

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        ListNode* res = new ListNode();
        ListNode* head = NULL;
        ListNode* temp;

        // while 2 lists are not empty
        while ((list1 != NULL) && (list2 != NULL)) {
            if (list1->val < list2->val) {
                temp = new ListNode(list1->val);
                list1 = list1->next;
            }
            else {
                temp = new ListNode(list2->val);
                list2 = list2->next;
            }
            if (head == NULL) {
                res->val = temp->val;
                head = res;
            }
            else {
                head->next = temp;
                head = head->next;
            }
        }

        // append rest in left if any
        while ((list1 != NULL)) {
            temp = new ListNode(list1->val);
            list1 = list1->next;
            head->next = temp;
            head = head->next;
        }

        // append rest in right if any
        while ((list2 != NULL)) {
            temp = new ListNode(list2->val);
            list2 = list2->next;
            head->next = temp;
            head = head->next;
        }

        return res;
    }
};