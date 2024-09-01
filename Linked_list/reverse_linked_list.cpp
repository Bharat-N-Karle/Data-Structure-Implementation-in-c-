#include <iostream>
using namespace std;

// Node structure for a singly linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the linked list
void insertNode(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Node inserted with value: " << data << endl;
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    cout << "Linked list reversed." << endl;
}

// Main function with menu-driven options
int main() {
    Node* head = nullptr;
    int choice, data;

    do {
        cout << "\n---- Linked List Operations Menu ----\n";
        cout << "1. Insert Node\n";
        cout << "2. Display List\n";
        cout << "3. Reverse List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> data;
                insertNode(head, data);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                reverseList(head);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
