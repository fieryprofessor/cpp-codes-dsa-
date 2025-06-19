//Bitwise Operations in Bit Manipulation
#include <bits/stdc++.h>
using namespace std;

int main(){

    int a = 5;    // 0101
    int b = 3;    // 0011

    int and_result = a & b;
    int or_result = a | b;
    int xor_result = a ^ b;
    int not_a = ~a;
    int left_shift = a << 1;
    int right_shift = a >> 1;

    cout << "a & b = " << and_result << endl;
    cout << "a | b = " << or_result << endl;
    cout << "a ^ b = " << xor_result << endl;
    cout << "~a = " << not_a << endl;
    cout << "a << 1 = " << left_shift << endl;
    cout << "a >> 1 = " << right_shift << endl;
    return 0;
}

//time:O(1)
//space:O(1)

//Formulas
//And: if all are 1's then 1 otherwise 0.
//Or: if atleast one 1 then 1 otherwise 0.
//Xor: Odd number of ones then 1 otherwise 0.
//LeftShift: multiply the number by 2^k where k is the number of shifts.
//RightShift: divide the number by 2^k where k is the number of shifts.
//Not: for positive no. ~(x)= -(x+1) and  for a negative no. ~(-x)= x-1