#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *slow = &dummy;
        ListNode *fast = &dummy;

        for (size_t i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *temp = slow->next;
        slow->next = temp->next;
        delete temp;

        return dummy.next;
    }
};

void addNode(ListNode *head, int val) {
    ListNode *newNode = new ListNode(val);
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = newNode;
}

int main() {
    Solution sol;
    ListNode *head = new ListNode(1);

    for (size_t i = 2; i <= 5; i++) {
        addNode(head, i);
    }

    head = sol.removeNthFromEnd(head, 2);

    for (ListNode *curr = head; curr != nullptr; curr = curr->next) {
        cout << curr->val << " -> ";
    }
    cout << "null" << endl;

    return 0;
}