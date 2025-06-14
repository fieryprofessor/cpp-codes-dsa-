//Remove the nth node from the list.
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

void removeNthNode(Node* &head, int n){
    if(!head->next){
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    Node* temp = head;
    for(int i=0;i<n;i++){
        temp = temp->next;
    }

    if (!temp) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    
    while(temp->next){
        temp=temp->next;
        curr = curr->next;
    }
    
    Node* toDelete = curr->next;
    curr->next= curr->next->next;
    delete toDelete;
}


int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    display(head);
    int n = 3;
    removeNthNode(head,n);
    display(head);
    return 0;
}

//time:O(n)
//space:O(1)