// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.
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


Node* reverseBetween2(Node* head, int left, int right) {

    if(head == nullptr || left == right)
        return head;

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;

    // Move prev to node before left
    for(int i = 1; i < left; i++)
        prev = prev->next;

    Node* curr = prev->next;
    Node* first = curr;

    Node* previous = nullptr;

    // Reverse exactly (right-left+1) nodes
    for(int i = 0; i <= right-left; i++){
        Node* next = curr->next;
        curr->next = previous;
        previous = curr;
        curr = next;
    }

    // Connect both ends
    prev->next = previous;
    first->next = curr;

    Node* newHead = dummy->next;
    delete dummy;

    return newHead;
}


Node* reverseBetween(Node* head, int left, int right) {
        if(head == nullptr || left == right)
            return head;

        Node* dummy = new Node(0);
        dummy->next = head;

        Node* prev = dummy;

        for(int i = 1; i < left; i++)
            prev = prev->next;

        Node* curr = prev->next;

        for(int i = 0; i < right-left; i++){
            Node* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

int main() {
    Node* head = nullptr;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    head = reverseBetween(head,2,4);
    display(head);
    return 0;
}

//time: O(n)
//space: O(1)