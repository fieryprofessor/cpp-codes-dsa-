//You are given an array of k linked-lists lists, each linked-list is sorted in 
//ascending order.Merge all the linked-lists into one sorted linked-list and return it.
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

Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int,Node*>>> minHeap;

        for(int i=0;i<lists.size();i++){
            if(lists[i])
            minHeap.push({lists[i]->data,lists[i]});
        }
        Node* dummyHead = new Node(-1);
        Node* temp = dummyHead;

        while(!minHeap.empty()){
            pair<int,Node*> p= minHeap.top();
            temp->next = p.second;
            minHeap.pop();
            if(p.second->next)
            minHeap.push({p.second->next->data,p.second->next});
            temp = temp->next;
        }
        return dummyHead->next;
    }

int main(){
    vector<Node*> lists(3, nullptr);

    // List 1: 1 -> 4 -> 5
    lists[0] = new Node(1);
    insertAtTail(lists[0], 4);
    insertAtTail(lists[0], 5);

    // List 2: 1 -> 3 -> 4
    lists[1] = new Node(1);
    insertAtTail(lists[1], 3);
    insertAtTail(lists[1], 4);

    // List 3: 2 -> 6
    lists[2] = new Node(2);
    insertAtTail(lists[2], 6);

    // Merge all lists
    Node* merged = mergeKLists(lists);

    // Display the merged linked list
    cout << "Merged Linked List:" << endl;
    display(merged);

    return 0;
}

//time:O(nlogk)
//space:O(k)