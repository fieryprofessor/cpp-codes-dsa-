//Given the head of a sorted singly linked list, delete all duplicates 
//such that each element appears only once. 
//Return the linked list sorted as well.
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

 Node* deleteDuplicates(Node* &head) {
        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        return head;
    }

int main(){
    Node* head = new Node(1);
    insertAtTail(head,1);   
    insertAtTail(head,2);   
    insertAtTail(head,3);   
    insertAtTail(head,3); 
    deleteDuplicates(head);
    display(head);
    return 0;
}

//time:O(n)
//space:O(1)