//queue
#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;// Follows FIFO
    q.push(1);//{1}
    q.push(2);//{1,2}
    q.emplace(3);//{1,2,3}
    q.back() += 4;//{1,2,7}
    cout<<q.back()<<endl;
    cout<<q.front()<<endl;
    q.pop();//{2,7}
    return 0;
}