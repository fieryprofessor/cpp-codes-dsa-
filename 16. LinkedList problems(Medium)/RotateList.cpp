//Given the head of a linked list, rotate the list to the right by k places.
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

Node* rotateRight(Node* head, int k) {
        if(head==nullptr || head->next==nullptr)
        return head;

        int n = 0;
        Node* temp = head;
        while(temp!=nullptr){
            temp=temp->next;
            n++;
        }
        k=k%n;
        temp = head;
        for(int i=0;i<k;i++){
            temp = temp->next;
        }
        Node* curr = head;
        while(temp->next!=nullptr){
            temp=temp->next;
            curr=curr->next;
        }
        temp->next =head;
        Node* newHead = curr->next;
        curr->next = nullptr;
        return newHead;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    int k = 2;
    Node* newHead = rotateRight(head,k);
    display(newHead);
    return 0;
}

//time:O(n)
//space:O(1)