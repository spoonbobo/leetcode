/*
    O(n) solution, beats 70 % time, 95 % space
*/

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
    ListNode* deleteDuplicates(ListNode* head) {
        // trivial cases
        if (head == nullptr) return head;

        ListNode* temp = head;
        ListNode* agent;

        while (temp->next != NULL) {
            if (temp->val != temp->next->val) {
                // good to go
                temp = temp->next;
            }
            else {
                // not good
                agent = temp;

                while (agent->next != NULL) {
                    if (agent->next->val != temp->val) {
                        temp->next = agent->next;
                        break;
                    }
                    else
                        agent = agent->next;
                }

                if (agent->next == NULL) {
                    if (agent->val != temp->val) {
                        temp->next = agent;
                    }
                    else {
                        temp->next = NULL;
                    }
                    return head;
                }
            }
        }

        return head;
    }
};