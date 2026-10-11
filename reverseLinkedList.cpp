#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* temp;

        while (curr != nullptr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};

void addNode(ListNode* head, int val) {
    ListNode* newNode = new ListNode(val);

    while (head->next != nullptr) {
        head = head->next;
    }

    head->next = newNode;
}

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    addNode(head, 2);
    addNode(head, 3);
    addNode(head, 4);
    addNode(head, 5);

    ListNode* result = sol.reverseList(head);

    for (ListNode* curr = result; curr != nullptr; curr = curr->next) {
        cout << curr->val << " -> ";
    }
    cout << "null" << endl;

    return 0;
}