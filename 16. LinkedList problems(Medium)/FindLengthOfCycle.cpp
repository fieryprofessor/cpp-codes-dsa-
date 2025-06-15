//Find the length of the cycle in the list.
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

int lengthCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)
        break;
    }
    if(slow!=fast)
    return 0;

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }
    int count = 1;
    Node* temp = slow->next;
    while(temp!=slow){
        count++;
        temp= temp->next;
    }
    return count;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    head->next->next->next->next->next = head->next->next;
    int result = lengthCycle(head);
    cout<<result<<endl;
    return 0;
}

//time:O(n)
//space:O(1)