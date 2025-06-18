//Sort the given linked list.
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

Node* middleElement(Node* &head){
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;
    while(fast && fast->next){
        prev = slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(prev != nullptr)
     prev->next = nullptr;
    return slow;
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

Node* sortLL(Node* &head){
    if(head==nullptr || head->next==nullptr)
    return head;

    Node* middle = middleElement(head);
    Node* left = sortLL(head);
    Node* right = sortLL(middle);
    return mergeTwoLists(left, right);
}

int main(){
    Node* head = new Node(3);
    insertAtTail(head,4);
    insertAtTail(head,2);
    insertAtTail(head,1);
    insertAtTail(head,5);
    display(head);
    Node* newHead = sortLL(head);
    display(newHead);
    return 0;
}

//time:O(nlogn)
//space:O(1)