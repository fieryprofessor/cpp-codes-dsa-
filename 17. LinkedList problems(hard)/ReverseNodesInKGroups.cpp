//Given the head of a linked list, reverse the nodes of the list k at a time, 
//and return the modified list.
//k is a positive integer and is less than or equal to the length of the linked list. 
//If the number of nodes is not a multiple of k then left-out nodes, in the end, 
//should remain as it is.
//You may not alter the values in the list's nodes, only nodes themselves may be changed.
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

Node* getKthNode(Node* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }

Node* reverseList(Node* &head){
    if(!head || !head->next)
    return head;

    Node* prev = head;
    Node* temp = head->next;
    while(temp){
        Node* front = temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    head->next = nullptr; 
    return prev;
}    

Node* reverseKGroup(Node* head, int k) {
        Node* temp = head; 
        Node* prevLast = NULL; 
    
    while(temp != NULL){
        Node* kThNode = getKthNode(temp, k); 

        if(kThNode == NULL){
            if(prevLast){
                prevLast -> next = temp; 
            }
            break; 
        }
        Node* nextNode = kThNode -> next; 
        kThNode -> next = NULL; 
        reverseList(temp); 
        
        if(temp == head){
            head = kThNode;
        }else{
            prevLast -> next = kThNode; 
        }
        prevLast = temp; 
        temp = nextNode; 
    }
    return head; 
    }

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    display(head);
    int k = 2;
    Node* newHead = reverseKGroup(head,k);
    display(newHead);
    return 0;
}

//time:O(n)
//space:O(1)