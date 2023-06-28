
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // trivial cases
        if ((list1 == NULL) && (list2 == NULL))
        {
            return NULL;
        }

        ListNode* res = NULL;
        ListNode* head = res;

        // while 2 lists are not empty
        // compare and append res

        // append rest in left if any

        // append rest in right if any

        return res;
    }
};