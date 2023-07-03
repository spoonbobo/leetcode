
 //Definition for singly-linked list.

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
#include <iostream>
#include <vector>

using namespace std;

// this solution is too slow, has to be optimised

void merge(ListNode* left, ListNode* right, vector<ListNode*>& temp_res) {
    ListNode* merged = new ListNode();
    ListNode* head = nullptr;
    ListNode* temp;

    // handle some extreme cases there
    if ((left == NULL) && (right == NULL)) {
        temp_res.push_back(nullptr);
        return;
    }

    if (left == NULL) {
        temp_res.push_back(right);
        return;
    }

    if (right == NULL) {
        temp_res.push_back(left);
        return;
    }

    while ((left != NULL) && (right != NULL)) {
        if ((left->val) < (right->val)) {
            temp = new ListNode(left->val, nullptr);
            left = left->next;
        }
        else {
            temp = new ListNode(right->val, nullptr);
            right = right->next;
        }
        if (head == NULL) {
            merged->val = temp->val;
            head = merged;
        }
        else {
            head->next = temp;
            head = head->next;
        }
    }

    while (left != NULL) {
        temp = new ListNode(left->val);
        left = left->next;
        head->next = temp;
        head = head->next;
    }

    while (right != NULL) {
        temp = new ListNode(right->val);
        right = right->next;
        head->next = temp;
        head = head->next;
    }

    temp_res.push_back(merged);
}

ListNode* mergeSort(vector<ListNode*>& lists, int N) {
    ListNode* res = nullptr;
    int left;
    while (lists.size() != 1) {
        vector<ListNode*> temp;
        left = 0;
        while (left < lists.size()) {
            if ((left + 1 == lists.size())) {
                temp.push_back(lists[left]);
            }
            else {
                merge(lists[left], lists[left + 1], temp);
            }
            left += 2;
        }
        lists = temp;
    }

    return lists[0];
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // trivial cases
        if (lists.size() == 0) return NULL;

        if (lists.size() == 1) return lists[0];

        ListNode* res = nullptr;

        res = mergeSort(lists, lists.size());

        return res;
    }
};