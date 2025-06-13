//You are given two non-empty linked lists representing two non-negative integers. 
//The digits are stored in reverse order, and each of their nodes contains a single digit. 
//Add the two numbers and return the sum as a linked list.
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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

Node* addTwoNumbers(Node* l1, Node* l2) {
        int rem=0;
        Node* head = new Node(0);
        Node* temp = head;

        while(l1!=nullptr||l2!= nullptr||rem){
            int sum = rem;
            if (l1) {
                sum += l1->data;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->data;
                l2 = l2->next;
            }
            rem = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        return head->next;
    }

int main(){
    Node* head1 = new Node(2);
    insertAtTail(head1,4);
    insertAtTail(head1,3);
    display(head1);

    Node* head2 = new Node(5);
    insertAtTail(head2,6);
    insertAtTail(head2,4);
    display(head2);

    Node* head = addTwoNumbers(head1,head2);
    display(head);

    return 0;
}

//time:O(max(n1,n2))
//space:O(max(n1,n2))