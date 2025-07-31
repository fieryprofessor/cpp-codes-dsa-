//Implementation of Stack using two Queues.
#include <bits/stdc++.h>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2;

public:
    MyStack() {
    }

    void push(int x) {
        q2.push(x);
        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2
        swap(q1, q2);
    }

    int pop() {
        if (q1.empty()) return -1;
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // 30
    cout << "Pop: " << stack.pop() << endl;         // 30
    cout << "Top element: " << stack.top() << endl; // 20

    stack.pop();
    stack.pop();

    if (stack.empty()) {
        cout << "Stack is now empty." << endl;
    } else {
        cout << "Stack is not empty." << endl;
    }

    return 0;
}
//time complexity of push is O(n) and pop, top, empty is O(1)
//space complexity is O(n) where n is the number of elements in the stack.
