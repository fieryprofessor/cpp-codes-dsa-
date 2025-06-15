//Intersection of two lists
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

Node* findIntersection(Node* &head1, Node* &head2){
    Node* a = head1;
    Node* b = head2;
    while(a!=b){
        a = a!=nullptr?a->next:head2;
        b = b!=nullptr?b->next:head1;
    }
    return a;
}

int main(){
    Node* head1 = new Node(1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    Node* head2 = new Node(1);
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    head2->next->next->next = head1->next->next;

    Node* intersection = findIntersection(head1,head2);
    cout<<intersection->data<<endl;
    return 0;
}

//time:O(n+m)
//space:O(1)