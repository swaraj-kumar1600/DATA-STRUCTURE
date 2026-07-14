#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void insertAtEnd(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next != NULL)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};

int main() {
    ListNode* head = NULL;

    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    printList(head);

    Solution obj;

    head = obj.reverseList(head);

    printList(head);

    return 0;
}