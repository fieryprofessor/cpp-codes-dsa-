//Double Linked List Structure
#include<bits/stdc++.h>
using namespace std;

//node of double linkedlist.
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

//converting array elements to double linkedlist
Node* convertArrToDLL(vector<int>&v){
    Node* head = new Node(v[0]);
    Node* curr = head;
    for(int i=1;i<v.size();i++){
        Node* temp = new Node(v[i]);
        temp->prev = curr;
        curr->next = temp;
        curr = curr->next;
    }
    return head;
}

//insert at the head
void insertAthead(Node* &head, int val){
    Node* node = new Node(val);
    node->next = head;
    if (head != nullptr) {
        head->prev = node;
    }
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
    node->prev = temp;
}

//insert at any Arbitrary position
void insertArbitrary(Node* head, int val , int pos){
    Node* node = new Node(val);
    Node* temp = head;
    for(int i=1;i<pos-1;i++){
        temp = temp->next;
    }
    if(temp==nullptr) 
    return;
    node->next = temp->next;
    node->prev = temp;
    if(temp->next != nullptr){
        temp->next->prev = node;
    }
    temp->next=node;
}

//delete at head
void deleteAtHead(Node* &head){
    Node* temp = head;
    head=head->next;
    head->prev=nullptr;
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
    temp->next = toDelete->next;
    if(toDelete->next!=nullptr){
        toDelete->next->prev=temp;
    }
    delete toDelete;
}

//traversing each node and displaying it.
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
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