//Implementation of Stack using Array in C++.
#include <bits/stdc++.h>
using namespace std;

class Stack {
private:
    int arr[100];  // fixed-size array with max limit
    int top;
    int size;      // fixed stack size = 10

public:
    // Constructor sets size to 10
    Stack() {
        size = 10;
        top = -1;
    }

    // Push element
    void push(int value) {
        if (top >= size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop element
    int pop() {
        if (top < 0) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Peek top
    int peek() {
        if (top < 0) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Stack s;  // size is fixed to 10

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();  // Output: 10 20 30

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();  // Output: 10 20

    return 0;
}

//time complexity: O(1) for push, pop, peek
//space complexity: O(n) where n is the size of the stack (fixed at 10)