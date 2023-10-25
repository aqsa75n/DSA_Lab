#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(NULL) {}
};

// Singly Linked List class
class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    // Function to insert a new node at the end of the list
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to check if the linked list is a palindrome
    bool SLL_SCND_FUNCTION_PALINDROME() {
        if (head == NULL) {
            return true; // An empty list is considered a palindrome
        }

        // Use a stack to store the first half of the linked list
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;

            // Reverse the first half of the list while traversing
            Node* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // If the total number of nodes is odd, move slow one step forward
        if (fast != NULL) {
            slow = slow->next;
        }

        // Compare the first half with the second half
        while (slow != NULL) {
            if (prev->data != slow->data) {
                return false;
            }
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};

int main() {
    LinkedList list;
   
    list.insert(1);
    list.insert(2);
    list.insert(1);
	     list.insert(1);

    if (list.SLL_SCND_FUNCTION_PALINDROME()) {
          cout << "The linked list is a palindrome." <<   endl;
    } else {
          cout << "The linked list is not a palindrome." <<   endl;
    }

    return 0;
}
