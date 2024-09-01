#include <iostream>
using namespace std;

#define MAX 100  // Maximum size of the queue

class Queue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the queue is full
    bool isFull() {
        return size == MAX;
    }

    // Add an element to the queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        size++;
        cout << value << " enqueued to the queue." << endl;
    }

    // Remove an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }
        cout << arr[front] << " dequeued from the queue." << endl;
        front = (front + 1) % MAX;
        size--;
    }

    // Display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % MAX] << " ";
        }
        cout << endl;
    }
};

void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Display" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Queue q;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
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
