/*
	Small improvement over Source1
	no need to let 'agent' recheck temp_i+1 node,
    simply start at temp_i+2, and if it's last node just check it
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
                agent = temp->next;

                // if next possible candidate if already last node, simply check
                if (agent->next == NULL) {
                    if (agent->val != temp->val) {
                        temp->next = agent;
                    }
                    else {
                        temp->next = NULL;
                    }
                    return head;
                }

                // try to find a candidate by traversing using agent
                while (agent->next != NULL) {
                    if (agent->next->val != temp->val) {
                        temp->next = agent->next;
                        break;
                    }
                    else
                        agent = agent->next;
                }

                // if we need to execute below code, that means above while loop failed to search until last node
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