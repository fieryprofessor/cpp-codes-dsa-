// Implementation of Queue using Array in C++.
#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    int arr[100]; // fixed-size array with max limit
    int front, rear;
    int size;     // fixed size = 10

public:
    // Constructor
    Queue() {
        size = 10;
        front = 0;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear >= size - 1) {
            cout << "Queue Overflow\n";
            return;
        }
        arr[++rear] = value;
    }

    // Dequeue operation
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }

    // Peek front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Display the queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();  // Output: 10 20 30

    cout << "Front element: " << q.peek() << endl;

    q.dequeue();
    q.display();  // Output: 20 30

    return 0;
}
//time complexity: O(1) for enqueue, dequeue, peek
//space complexity: O(n) where n is the size of the queue (fixed at 10)