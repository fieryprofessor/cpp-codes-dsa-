//Sort the linked list containing zeroes, ones and twos.
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

Node* sortList(Node* head){
    if(!head || !head->next)
    return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    Node* temp = head;

    while(temp){
        if(temp->data==0){
            zero->next = temp;
            zero = temp;
        }
        else if(temp->data==1){
            one->next = temp;
            one = temp;
        }
        else{
            two->next = temp;
            two = temp;
        }
        temp=temp->next;
    }

    zero->next = oneHead->next?oneHead->next:twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node* newHead = zeroHead->next;
    delete oneHead;
    delete twoHead;
    delete zeroHead;
    return newHead;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,0);
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,0);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    Node* head2 = sortList(head);
    display(head2);
    return 0;
}

//time:O(n)
//space:O(1)