#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Node inserted at the beginning.\n";
    }

    // Function to insert a node at the end
    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Node inserted at the end.\n";
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
        cout << "Node deleted from the beginning.\n";
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
        cout << "Node deleted from the end.\n";
    }

    // Function to display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to search for an element in the list
    void search(int key) {
        Node* temp = head;
        int position = 1;
        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Element " << key << " found at position " << position << ".\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element " << key << " not found in the list.\n";
    }
};

// Main function
int main() {
    DoublyLinkedList dll;
    int choice, data;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert at the beginning\n";
        cout << "2. Insert at the end\n";
        cout << "3. Delete from the beginning\n";
        cout << "4. Delete from the end\n";
        cout << "5. Display the list\n";
        cout << "6. Search for an element\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                dll.insertAtBeginning(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                dll.insertAtEnd(data);
                break;
            case 3:
                dll.deleteFromBeginning();
                break;
            case 4:
                dll.deleteFromEnd();
                break;
            case 5:
                dll.display();
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> data;
                dll.search(data);
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
