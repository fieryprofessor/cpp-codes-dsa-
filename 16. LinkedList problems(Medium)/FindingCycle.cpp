//Detect whether a cycle exist in the linkedlist or not.

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

bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        return true;
    }
    return false;
}
int main(){
    Node* head = new Node(1);
    Node* secondEle = new Node(2);
    Node* thirdEle = new Node(3);
    Node* fourthEle = new Node(4);
    head->next = secondEle;
    secondEle->next = thirdEle;
    thirdEle->next = fourthEle;
    fourthEle->next = head;

    bool cyclePresent = detectCycle(head);
    cout<<cyclePresent<<endl;
    return 0;
}

//time:O(n)
//space:O(1)