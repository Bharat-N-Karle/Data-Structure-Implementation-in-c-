#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
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

// Function to remove duplicates from a sorted linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;

    Node* current = head;

    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node* duplicateNode = current->next;
            current->next = current->next->next;
            delete duplicateNode;
        } else {
            current = current->next;
        }
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Insert element" << endl;
    cout << "2. Display list" << endl;
    cout << "3. Remove duplicates" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node* head = nullptr;
    int choice, data;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter an element to insert: ";
                cin >> data;
                insertNode(head, data);
                cout << "Element inserted." << endl;
                break;

            case 2:
                cout << "Linked List: ";
                displayList(head);
                break;

            case 3:
                removeDuplicates(head);
                cout << "Duplicates removed." << endl;
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
