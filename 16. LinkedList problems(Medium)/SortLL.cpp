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
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        

        while (list1 != nullptr && list2 != nullptr) {

        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

       if(list1!=nullptr)
       temp->next = list1;
       else
       temp->next = list2;

        Node* newHead = dummy->next;
        delete dummy;
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