//Reverse a Double LinkedList
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

Node* reverse(Node* head){
    Node* current = head;
    Node* last = nullptr;
    while(current!=nullptr){
        last = current->prev;
        current->prev=current->next;
        current->next=last;
        current = current->prev;
    }
    return last->prev;
}

int main(){
    Node* head = new Node(5);
    insertAtTail(head,4);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    Node* head2= reverse(head);
    display(head2);
    return 0;
}

//time:O(n)
//space:O(1)