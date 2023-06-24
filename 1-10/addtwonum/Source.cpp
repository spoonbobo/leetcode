#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = NULL;
        ListNode* temp;
        ListNode* ptr;
        int sum;
        bool trailing = false;

        while (true) {
            // if both are null ptrs, check whether there is trailing digit
            // if yes insert this, otherwise done.
            sum = 0;
            if ((l1 == NULL) && (l2 == NULL)) {
                if (trailing) {
                    ptr = res;
                    while (ptr->next != NULL) {
                        ptr = ptr->next;
                    }
                    ptr->next = new ListNode(1, nullptr);
                }
                break;
            };

            // add trailing if any
            if (trailing) {
                sum += 1;
            }

            // check first val
            if (l1 != NULL)
                sum += l1->val;

            if (l2 != NULL)
                sum += l2->val;

            // check trailing
            if (sum >= 10) trailing = true;
            else trailing = false;

            // get significant digit
            sum %= 10;

            // get the temp node ready
            temp = new ListNode(sum, nullptr);

            // insert the temp node at the end
            if (res == NULL)
                res = new ListNode(temp->val, nullptr);
            else {
                ptr = res;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = temp;
            }

            // traverse
            if (l1 != NULL)
                l1 = l1->next;
            if (l2 != NULL)
                l2 = l2->next;
        }

        return res;
    }
};