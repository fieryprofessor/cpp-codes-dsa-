// Given two integers n and m (m != 0). Find the number closest to n and divisible by m. If there
// is more than one such number, then output the one having maximum absolute value.
#include <bits/stdc++.h>
using namespace std;

int closestNumber(int &n, int &m)
{
    int q = n / m;
    int n1 = m * q;
    int n2 = (n * m) < 0 ? m * (q - 1) : m * (q + 1);
    if (abs(n - n1) < abs(n - n2))
    return n1;
    return n2;
}

int main()
{
    int n = 13, m = 4;
    int ans = closestNumber(n, m);
    cout << ans;
    return 0;
}

//time: O(1)
//space: O(1)