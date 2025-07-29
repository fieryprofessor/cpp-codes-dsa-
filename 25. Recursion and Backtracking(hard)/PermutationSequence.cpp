// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order,
// we get the following sequence for n = 3:
// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.
#include<bits/stdc++.h>
using namespace std;

string getPermutation(int n, int k) {
         int fact = 1;
        vector<int> numbers;
        
        for (int i = 1; i < n; i++) {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1;
        while (true) {
            ans = ans + to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }

    int main() {
    int n = 4;
    int k = 9;

    string result = getPermutation(n, k);
    cout << result << endl;

    return 0;
}

//time: O(n)
//space: O(n)