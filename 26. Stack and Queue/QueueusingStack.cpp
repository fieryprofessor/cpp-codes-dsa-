// Implementation of Queue using two Stacks.
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        int front = s2.top();
        s2.pop();
        return front;
    }

    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        return s2.top();
    }

    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.peek() << endl; // 1
    cout << "Pop: " << q.pop() << endl;    // 1
    cout << "Front: " << q.peek() << endl; // 2

    q.pop();
    q.pop();

    if (q.empty()) {
        cout << "Queue is now empty." << endl;
    } else {
        cout << "Queue is not empty." << endl;
    }

    return 0;
}

//time complexity of push is O(1), pop and peek are O(n) in the worst case, and empty is O(1).
//space complexity is O(n) for storing elements in the stacks.
