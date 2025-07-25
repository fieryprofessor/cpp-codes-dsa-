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
        Node* dummy = new Node(-1);
        Node* temp = dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Attach remaining nodes
    temp->next = (list1 != nullptr) ? list1 : list2;

    Node* mergedHead = dummy->next;
    delete dummy;
    return mergedHead;
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