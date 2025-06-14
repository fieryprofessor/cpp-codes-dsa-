//Find if the list is palindrome or not.
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

bool isPalindrome(Node* head) {
    if(head==nullptr || head->next==nullptr)
    return true;

    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second){
        if(first->data!=second->data){
            reverseList(newHead);
            return false;
        }
        
        first= first->next;
        second = second->next;
    }
    reverseList(newHead);
    return true;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,2);
    insertAtTail(head,1);
    display(head);
    bool isPalin = isPalindrome(head);
    cout<<isPalin<<endl;
    return 0;
}

//time:O(2n)
//space:O(1)