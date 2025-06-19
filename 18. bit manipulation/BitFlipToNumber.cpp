//Minimum bit flips to convert a number.
//Given two integers start and goal, return the minimum number of bit flips required to
//convert start into goal.
#include<bits/stdc++.h>
using namespace std;

int countSetBits( int n){
    int count =0;
   while(n!=0){
        if((n&1)==1)
        count++;
        n = n>>1;
   }
   return count;
}

int minFlips(int start, int goal){
    int diff = start ^ goal;
    int count = countSetBits(diff);
    return count;
}

int main(){
    int start = 10;
    int goal = 7;
    int answer = minFlips(start,goal);
    cout<<answer;
    return 0;
}

//time:O(n) n = no. of bits in the start^goal.
//space:O(1)