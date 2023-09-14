// O(n) solution, beats 100% time

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

 // euclid algorithm
int get_gcd(const int& a, const int& b) {
    int r, dividend, divisor;
    if (a > b) {
        dividend = a;
        divisor = b;
    }
    else {
        dividend = b;
        divisor = a;
    }
    while (true) {
        r = dividend % divisor;
        if (r == 0)
            return divisor;
        dividend = divisor;
        divisor = r;
    }
    return -1;
}

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* filter = head;
        ListNode* newnode;
        while (filter->next != nullptr) {

            // find gcd and insert
            newnode = new ListNode(get_gcd(filter->val, filter->next->val));
            newnode->next = filter->next;
            filter->next = newnode;

            // traverse
            filter = filter->next->next;
        }
        return head;
    }
};