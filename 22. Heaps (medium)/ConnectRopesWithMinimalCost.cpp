//You are given an array of stick lengths. You can connect any two sticks at a time,
//and the cost is equal to the sum of their lengths.Return the minimum total cost 
//to connect all sticks into one.
#include<bits/stdc++.h>
using namespace std;

int connectSticks(vector<int> &sticks){
    priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int a = minHeap.top(); minHeap.pop();
        int b = minHeap.top(); minHeap.pop();
        int cost = a + b;
        totalCost += cost;
        minHeap.push(cost);
    }
    return totalCost;
}

int main(){
    vector<int>sticks = {2, 4, 3};
    int answer = connectSticks(sticks);
    cout<<answer<<endl;
    return 0;
}

//time:O(n)
//space:O(n)