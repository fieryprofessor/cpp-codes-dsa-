// You are given the head of a singly linked-list. The list can be represented as:
// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:
// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.
#include <bits/stdc++.h>
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
    if(!head){
        head = node;
        return;
    }
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

void reorderList(Node* head) {
    if(head == nullptr || head->next == nullptr)
        return;

    // Find middle
    Node* slow = head;
    Node* fast = head;

    while(fast!= nullptr && fast->next!= nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    Node* prev = nullptr;
    Node* curr = slow->next;
    slow->next = nullptr;

    while(curr != nullptr){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Merge
    Node* first = head;
    Node* second = prev;

    while(second != nullptr){

        Node* next1 = first->next;
        Node* next2 = second->next;

        first->next = second;
        second->next = next1;

        first = next1;
        second = next2;
    }
}


int main() {
    Node* head = nullptr;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    reorderList(head);
    display(head);
    return 0;
}

//time: O(n)
//space: O(1)