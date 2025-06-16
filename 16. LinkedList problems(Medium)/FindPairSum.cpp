//Given a sorted doubly linked list and a target sum x,
// find all pairs of nodes such that the sum of their data equals x.
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

vector<pair<int,int>> pairSum(Node* &head, int sum){
    Node* low = head;
    Node* high = head;
    vector<pair<int,int>>ans;
    while(high->next){
        high = high->next;
    }
    while(low && high && low != high && low->prev != high){
        if(low->data+high->data==sum){
            ans.push_back({low->data,high->data});
            low = low->next;
            high = high->prev;
        }
        else if(low->data+high->data<sum){
            low = low->next;
        }
        else{
            high = high->prev;
        }
    }
    return ans;
}

int main(){
    Node* head = new Node(1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,9);
    display(head);
    int sum = 5;
    vector<pair<int,int>>v = pairSum(head,sum);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

//time:O(n)
//space:O(1)