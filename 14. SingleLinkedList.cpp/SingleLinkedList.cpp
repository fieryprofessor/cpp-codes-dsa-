//Single Linked List Structure
#include<bits/stdc++.h>
using namespace std;

//node class(we can also use struct)
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = nullptr;
    }
};

//Convert array elements into linkedlist nodes.
Node* convertArrToLL(vector<int>&v){
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1;i<v.size();i++){
        Node* ele = new Node(v[i]);
        temp->next = ele;
        temp = ele;
    }
    return head;
}

//to find the length of the linkedlist.
int length(Node*head){
    Node* temp = head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

//to traverse and display all the nodes
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<endl;
}

//to search a target value in the list.
bool search(Node* head, int target){
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data==target)
        return true;
        temp = temp->next;
    }
    return false;
}

int main(){
    vector<int>v={1,2,3,4};
    Node* head = convertArrToLL(v);
    display(head);
    int count = length(head);
    cout<<count<<endl;
    bool isPresent = search(head,3);
    cout<<"3 is present: "<<isPresent<<endl;
    return 0;
}