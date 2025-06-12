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

//insert at the head
void insertAthead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    head = node;
}

//insert at the end
void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = node;
}

//insert at any Arbitrary position
void insertArbitrary(Node* head, int val , int pos){
    Node* node = new Node(val);
    Node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next=node;
}

//delete at head
void deleteAtHead(Node* &head){
    Node* temp = head;
    head=head->next;
    delete temp;
}

//delete at tail
void deleteAtTail(Node* &head){
    if(head->next==nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = nullptr;
    delete toDelete;
}

//delete at any Arbitrary position
void deleteAtArbitrary(Node* &head, int pos){
    Node* temp = head;

    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


//display list
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

int main(){

    Node* head = new Node(1);
    display(head);
    insertAthead(head,2);
    display(head);
    insertAtTail(head,3);
    display(head);
    insertArbitrary(head,4,2);
    display(head);

    cout<<endl;

    Node* head2 = new Node(1);
    insertAtTail(head2,2);
    insertAtTail(head2,3);
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    display(head2);
    deleteAtHead(head2);
    display(head2);
    deleteAtTail(head2);
    display(head2);
    deleteAtArbitrary(head2,2);
    display(head2);
    
    return 0;
}