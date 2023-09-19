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

 // 2scan solution (O(n) time; O(1) space)

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        int n = 0;
        ListNode* filter = head;
        while (filter->next != nullptr) {
            n++; filter = filter->next;
        }
        while (head != nullptr) {
            res += head->val * pow(2, n);
            n--; head = head->next;
        }
        return res;
    }
};