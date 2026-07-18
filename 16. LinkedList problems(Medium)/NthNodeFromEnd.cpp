//Remove the nth node from the list.
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = node;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

void removeNthFromEnd(Node* &head, int n) {
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    // Move fast n steps ahead
    for (int i = 1; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node from the end
    Node* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    // Store the new head
    Node* newHead = dummy->next;

    // Delete the dummy node
    delete dummy;
    head = newHead;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    display(head);
    int n = 3;
    removeNthFromEnd(head,n);
    display(head);
    return 0;
}

//time:O(n)
//space:O(1)