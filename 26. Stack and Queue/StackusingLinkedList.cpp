// Stack using Linked List in C++.
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Stack class using linked list
class Stack {
private:
    Node* top;  // Pointer to top node

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    // Pop operation
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return -1;
        }
        int popped = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return popped;
    }

    // Peek (top element)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is Empty\n";
            return;
        }
        Node* curr = top;
        cout << "Stack elements: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Driver code
int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();  // Output: 30 20 10

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.display();  // Output: 20 10

    return 0;
}

//time complexity: O(1) for push, pop, and peek operations
//space complexity: O(n) where n is the number of elements in the stack