#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory allocation failed.\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to insert a node at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    cout << "Node inserted at the beginning.\n";
}

// Function to insert a node at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        head = newNode;
        cout << "Node inserted at the end.\n";
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Node inserted at the end.\n";
}

// Function to delete a node by value
void deleteByValue(Node*& head, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node with value " << value << " deleted.\n";
        return;
    }
    Node* temp = head;
    while (temp->next && temp->next->data != value) {
        temp = temp->next;
    }
    if (!temp->next) {
        cout << "Node with value " << value << " not found.\n";
        return;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    cout << "Node with value " << value << " deleted.\n";
}

// Function to display the linked list
void displayList(Node* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Function to search for a node by value
void searchNode(Node* head, int value) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    int pos = 0;
    while (temp) {
        if (temp->data == value) {
            cout << "Node with value " << value << " found at position " << pos << ".\n";
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Node with value " << value << " not found.\n";
}

// Main function
int main() {
    Node* head = nullptr;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete by value\n";
        cout << "4. Display list\n";
        cout << "5. Search by value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at the beginning: ";
                cin >> value;
                insertAtBeginning(head, value);
                break;
            case 2:
                cout << "Enter value to insert at the end: ";
                cin >> value;
                insertAtEnd(head, value);
                break;
            case 3:
                cout << "Enter value to delete: ";
                cin >> value;
                deleteByValue(head, value);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(head, value);
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}