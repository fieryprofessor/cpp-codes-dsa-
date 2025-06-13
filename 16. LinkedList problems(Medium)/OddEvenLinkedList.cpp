//Given the head of a singly linked list, group all the nodes with odd indices together
// followed by the nodes with even indices, and return the reordered list.
//The first node is considered odd, and the second node is even, and so on.
//Note that the relative order inside both the even and odd groups should remain 
//as it was in the input.
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

Node* oddEvenList(Node* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)
        return head;
        Node* odd = head;
        Node* even = head->next;
        Node* temp = even;
        Node* curr = even->next;
        int count =3;
         while(curr!=nullptr){
            if(count%2==1){
                odd->next = curr;
                odd=odd->next;
            }
            else{
                even->next = curr;
                even = even->next;
            }
            count++;
            curr = curr->next;
         }
         odd->next = temp;
         even->next = nullptr;
         return head;
    }

int main(){
    Node* head = new Node(2);
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,4);
    insertAtTail(head,7);
    display(head);
    Node* head2 = oddEvenList(head);
    display(head2);
    return 0;
}

//time:O(n)
//space:O(1)