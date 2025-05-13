//deque
#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(1);
    dq.emplace_front(2);
    dq.pop_back();
    dq.pop_front();
    dq.back();// reference to last element
    dq.front();// reference to first element
    cout<<dq[2];
    return 0;
}