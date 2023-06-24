#include <iostream>
#include <iterator>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

void printList(ListNode* l) {
	while (true) {
		cout << l->val << " ";
		if (l->next == NULL) break;
	}
	cout << endl;
}

void initList(ListNode* l, uint32_t arr[], size_t n) {
	ListNode* head = new ListNode();
	head = l;
	for (int i = 0; i < n; i++) {
		head->val = arr[i];
		head = head->next;
	}
}

int main() {
	uint32_t arr1[3] = {2, 4, 3};
	uint32_t arr2[3] = {5, 6, 4 };

	size_t n1 = size(arr1);
	size_t n2 = size(arr2);

	initList(l1, arr1, n1);

	return 0;
}