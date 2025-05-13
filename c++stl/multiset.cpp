//multiset
#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> ms; //it stores elements in sorted order.
    ms.insert(1);
    ms.insert(2);
    ms.insert(2);
    ms.insert(3);
    ms.insert(3);

    ms.erase(2); //all 2's are erased.
    int count = ms.count(3); // gives 2 as 3 repeats 2 times in ms.
    return 0;
}