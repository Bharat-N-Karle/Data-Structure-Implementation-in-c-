#include <iostream>
using namespace std;

// Node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Class for the doubly linked list
class DoublyLinkedList {
private:
    Node* head; // Head pointer

public:
    DoublyLinkedList() : head(nullptr) {} // Constructor to initialize the head

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);

        if (!head) {
            head = newNode; // If the list is empty, make the new node the head
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next; // Traverse to the last node
            }
            temp->next = newNode; // Link the new node at the end
            newNode->prev = temp;
        }

        cout << "Node inserted: " << data << endl;
    }

    // Function to display the list
    void displayList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to reverse the list
    void reverseList() {
        if (!head || !head->next) {
            cout << "List is empty or has only one node, no need to reverse." << endl;
            return;
        }

        Node* current = head;
        Node* temp = nullptr;

        // Swap next and prev pointers for each node to reverse the list
        while (current) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }

        // After reversing, set the head to the last node
        if (temp) {
            head = temp->prev;
        }

        cout << "List reversed." << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// Main function
int main() {
    DoublyLinkedList list;
    int choice, data;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at End\n";
        cout << "2. Display List\n";
        cout << "3. Reverse List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the data to insert: ";
            cin >> data;
            list.insertAtEnd(data);
            break;
        case 2:
            list.displayList();
            break;
        case 3:
            list.reverseList();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
