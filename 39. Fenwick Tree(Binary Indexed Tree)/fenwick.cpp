#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    int n;
    vector<int> bit;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    // Add val to the element at index i
    void update(int i, int val) {

        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    // Sum of elements from index 0 to i
    int prefixSum(int i) {
        int sum = 0;

        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }

    // Sum of elements from L to R, inclusive
    int rangeSum(int L, int R) {
        if (L == 0)  return prefixSum(R);

        return prefixSum(R) - prefixSum(L - 1);
    }
};

int main() {
    vector<int> arr = {2, 1, 3, 4, 5};
    int n = arr.size();

    FenwickTree fw(n);

    // Build the Fenwick Tree
    for (int i = 0; i < n; i++) {
        fw.update(i+1, arr[i]);
    }

    cout << fw.rangeSum(1, 3) << "\n";  // 6

    // Change arr[2] from 3 to 10
    int val = 10 - arr[2];
    arr[2] = 10;
    fw.update(2+1, val);

    cout << fw.rangeSum(1, 3) << "\n";  // 13

    return 0;
}
