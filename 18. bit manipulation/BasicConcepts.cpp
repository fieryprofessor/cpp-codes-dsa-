//Basic Concepts of Bit Manipulation
#include<bits/stdc++.h>
using namespace std;

//swapping of two numbers without using third variable
void swap (int &x, int &y){
    x = x^y;
    y = x^y;
    x = x^y;
}

//check if ith bit is set or not.
bool checkIthBit(int &n , int &i){
    return ((1<<i)&n)!=0;
}

//Set the ith bit.
void setIthBit(int &n , int &i){
    n = (1<<i)|n;
}

//Clear the ith bit.
void clearIthBit(int &n , int &i){
    n = ~(1<<i)&n;
}

//Toggle the ith bit.
void toggleIthBit(int &n , int &i){
    n = (1<<i)^n;
}

int main(){
    int x = 10;
    int y = 5;
    cout<<x<<" "<<y<<endl; //10 5
    swap(x,y);
    cout<<x<<" "<<y<<endl; // 5 10
    int n = 13;
    int i = 2;
    bool checkSet = checkIthBit(n,i); //1101 the bit at 2nd index from lsb is set so 1
    cout<<checkSet<<endl;
    i=1;
    setIthBit(n,i); //1101 sets the bit at index 1 so number becomes 1111 i.e. 15
    cout<<n<<endl;
    clearIthBit(n,i); //1101 clears the bit at index 1 so number becomes 1101 again i.e. 13
    cout<<n<<endl;
    return 0;
}

//time:O(1)
//space:O(1)