//You are given the heads of two sorted linked lists list1 and list2.
//Merge the two lists into one sorted list. The list should be made by splicing together 
//the nodes of the first two lists.
//Return the head of the merged linked list.
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

Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* head = new Node(-1);
        Node* temp = head;
        Node* temp1 = list1;
        Node* temp2 = list2;

        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->data <= temp2->data){
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp2 = temp2->next;
            }
            
            temp = temp->next;
        }

       if(temp1!=nullptr)
       temp->next = temp1;
       else
       temp->next = temp2;

        Node* newHead = head->next;
        delete head;
        return newHead;
    }

int main(){
    Node* head1 = new Node(1);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    display(head1);
    Node* head2 = new Node(1);
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    display(head2);
    Node* newHead = mergeTwoLists(head1,head2);
    display(newHead);

    return 0;
}

//time:O(n)
//space:O(1)