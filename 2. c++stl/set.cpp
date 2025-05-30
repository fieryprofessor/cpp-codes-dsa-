//set
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s; //it stores unique elements and in sorted order;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);

    auto it = s.find(2); // returns an iterator that points to 2.
    auto it2 = s.find(6); // returns an iterator that points to the s.end() as 6 is not present
    s.erase(3);
    int count = s.count(1); // as 1 is present it returns 1 otherwise would have returned 0.
    return 0;
}