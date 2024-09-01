#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;        // Pointer to array holding stack elements
    int top;         // Index of the top element in the stack
    int capacity;    // Maximum size of the stack

public:
    // Constructor to initialize stack
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1;   // Stack is empty initially
    }

    // Destructor to free allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push an element onto the stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed onto the stack." << endl;
    }

    // Pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        cout << arr[top--] << " popped from the stack." << endl;
    }

    // Peek at the top element of the stack
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Top element is " << arr[top] << endl;
    }

    // Display all elements in the stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Peek" << endl;
    cout << "4. Display" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                s.display();
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
