//list
#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> ls; //double linkedlist
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(1);
    ls.emplace_front(2);

    forward_list<int> ls2; //single linkedlist
    return 0;
}