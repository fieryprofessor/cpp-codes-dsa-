//Count the number of set bis.
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

int main(){
    int n = 15;
    cout<<n<<endl;
    int answer = countSetBits(n);
    cout<<answer;
    return 0;
}

//time:O(n) n = no. of bits in the number
//space:O(1)

//Alternate Approach we can also clear rightmost bits and update
//the count until the number becomes zero.