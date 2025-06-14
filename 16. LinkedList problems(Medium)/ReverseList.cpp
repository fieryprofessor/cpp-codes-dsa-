//Reverse the given linked list
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

int main(){
    Node* head = new Node(4);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    Node* head2 = reverseList(head);
    display(head2);
    return 0;
}

//time:O(n)
//space:O(1)