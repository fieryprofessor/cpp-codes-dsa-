//priority queue
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int> pq; // by default a max heap.
    pq.push(5);//{5}
    pq.push(2);//{5,2}
    pq.push(8);//{8,5,2}

    cout<<pq.top()<<endl;//8

    priority_queue<int,vector<int>,greater<int>> pq2; // its a min heap now
    pq2.push(5);//{5}
    pq2.push(2);//{2,5}
    pq2.push(8);//{2,5,8}

    cout<<pq2.top()<<endl;//2
    return 0;
}