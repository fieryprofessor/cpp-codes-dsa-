//counting set bits
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num = 7;
    int count = __builtin_popcount(num); // counts set bits in num.
    cout<<count;
    return 0;
}