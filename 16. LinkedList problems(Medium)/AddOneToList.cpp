//Add one to the list.
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

Node* reverseList(Node* &head){
    if(!head || !head->next)
    return head;

    Node* prev = head;
    Node* temp = head->next;
    while(temp){
        Node* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head->next = nullptr; 
    return prev;
}

void addOne(Node* &head){
    Node* newHead = reverseList(head);
    Node* temp = newHead;
    int carry = 1;
    while(carry>0 && temp!=nullptr){
        int value = temp->data+carry;
        temp->data=value%10;
        carry = value/10;
        temp = temp->next;
    }
    if(carry>0){
        insertAtTail(newHead,carry);
    }
    head = reverseList(newHead);
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,5);
    insertAtTail(head,9);
    display(head);
    addOne(head);
    display(head);
    return 0;
}

//time:O(n)
//space:O(1)

//There is also an efficient way to solve this using backtracking.