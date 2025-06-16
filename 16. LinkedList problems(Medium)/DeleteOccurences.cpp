//Given a doubly linked list and a key, delete all nodes from the list that contain this key.
#include<bits/stdc++.h>
using namespace std;

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

void insertAtTail(Node* &head, int val){
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
}

void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

void deleteOccurences(Node* &head, int key){
    Node* temp = head;
    while(temp){
        
        if(temp->data==key){
            if(temp==head)
            head = head->next;

            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode)
            nextNode->prev = prevNode;
            if(prevNode)
            prevNode->next = nextNode;

            delete temp; 
            temp = nextNode;
        }
        else
        temp = temp->next;
    }
}

int main(){
    Node* head = new Node(10);
    insertAtTail(head,4);
    insertAtTail(head,10);
    insertAtTail(head,10);
    insertAtTail(head,6);
    insertAtTail(head,10);
    display(head);
    int key = 10;
    deleteOccurences(head,key);
    display(head);
    return 0;
}

//time:O(n)
//space:O(1)