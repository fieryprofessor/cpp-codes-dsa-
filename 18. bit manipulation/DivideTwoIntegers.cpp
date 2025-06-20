//Given two integers dividend and divisor, divide two integers without using multiplication,
// division, and mod operator.
//The integer division should truncate toward zero, which means losing its fractional part.
// For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.
//Return the quotient after dividing dividend by divisor.
#include<bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;

        bool sign = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
            sign = false;

        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long quotient = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            quotient += (1L << cnt);
            n -= (d << cnt);
        }

        if (quotient > INT_MAX)
            return sign ? INT_MAX : INT_MIN;

        return sign ? quotient : -quotient;
    }

int main(){
    int dividend = 22;
    int divisor = 3;
    int quotient = divide(dividend, divisor);
    cout<<quotient<<endl;
    return 0;
}

//time:O(logn)
//space:O(1)