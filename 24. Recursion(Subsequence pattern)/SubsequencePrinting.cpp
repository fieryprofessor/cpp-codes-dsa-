//Given An array of integers arr[] of size n.
//Print all possible subsequences of the array. A subsequence is a sequence that can be
// derived by deleting zero or more elements without changing the order of the 
//remaining elements.
#include <iostream>
using namespace std;

void printSubsequences(int arr[], int n, int index = 0, string current = "") {
    // Base case: if we have considered all elements
    if (index == n) {
        cout << current << endl; // Print the current subsequence
        return;
    }

    // Include the current element in the subsequence
    printSubsequences(arr, n, index + 1, current + to_string(arr[index]) + " ");

    // Exclude the current element from the subsequence
    printSubsequences(arr, n, index + 1, current);
}

int main() {
    int arr[] = {3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "All possible subsequences are:\n";
    printSubsequences(arr, n);

    return 0;
}

//time: O(2^n) for n elements, as each element can either be included or excluded.
//space: O(n) for the recursion stack, where n is the size of the array

