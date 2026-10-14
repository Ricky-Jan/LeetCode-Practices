#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        tail->next = (list1 != nullptr) ? list1 : list2; 

        return dummy.next;
    }
};

int main() {
    Solution sol;

    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(4);

    ListNode* b1 = new ListNode(1);
    ListNode* b2 = new ListNode(3);
    ListNode* b3 = new ListNode(4);

    ListNode* list1 = a1;
    list1->next = a2;
    list1->next->next = a3;

    ListNode* list2 = b1;
    list2->next = b2;
    list2->next->next = b3;

    ListNode* result = sol.mergeTwoLists(list1, list2);

    for (ListNode* curr = result; curr != nullptr; curr = curr->next) {
        cout << curr->val << " -> ";
    }
    cout << "null" << endl;
    return 0;
}