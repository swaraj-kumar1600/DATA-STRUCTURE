#include <iostream>
using namespace std;

// Definition for singly-linked list
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

// Solution class
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        int count = 0;
        ListNode* temp = head;

        // Count the number of nodes
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Find the middle index
        int mid = count / 2;

        // Move to the middle node
        temp = head;
        while (mid--) {
            temp = temp->next;
        }

        return temp;
    }
};

// Function to insert a node at the end
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

// Function to print the linked list
void printList(ListNode* head) {

    ListNode* temp = head;

    while (temp != NULL) {
        cout << temp->val;

        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    ListNode* head = NULL;

    // Creating the linked list
    insertAtEnd(head, 1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);

    cout << "Linked List: ";
    printList(head);

    Solution obj;

    ListNode* middle = obj.middleNode(head);

    cout << "Middle Node: " << middle->val << endl;

    return 0;
}