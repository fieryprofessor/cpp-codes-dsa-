//Given an array of integers arr of size n and an integer targetSum, print all the 
//subsequences of the array whose sum is equal to k. A subsequence is a sequence derived
//by deleting zero or more elements without changing the order of the remaining elements.
#include<bits/stdc++.h>
using namespace std;

//This function finds all subsequences whose sum equals targetSum
//It uses backtracking to explore all possible subsequences.
//It prints each valid subsequence when found.
void findSubsequences(int index, vector<int>& arr, vector<int>& current, int targetSum, int currentSum) {
    if (index == arr.size()) {
        if (currentSum == targetSum) {
            for (int num : current) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    // Include the current element
    current.push_back(arr[index]);
    findSubsequences(index + 1, arr, current, targetSum, currentSum + arr[index]);

    // Exclude the current element
    current.pop_back();
    findSubsequences(index + 1, arr, current, targetSum, currentSum);
}

//This function finds one subsequence whose sum equals targetSum
//It returns true if such a subsequence is found, otherwise false.
bool findOneSubsequences(int index, vector<int>& arr, vector<int>& current, int targetSum, int currentSum) {
    if (index == arr.size()) {
        if (currentSum == targetSum) {
            for (int num : current) {
                cout << num << " ";
            }
            cout << endl;
            return true; // Found one valid subsequence
        } 
        return false; // No valid subsequence found
    }
        
    // Include the current element
    current.push_back(arr[index]);
    if(findOneSubsequences(index + 1, arr, current, targetSum, currentSum + arr[index])==true)
        return true;

    // Exclude the current element
    current.pop_back();
    if(findOneSubsequences(index + 1, arr, current, targetSum, currentSum)==true)
        return true;
    return false; // No valid subsequence found
}

//This function counts the number of subsequences whose sum equals targetSum
//It returns the count of such subsequences.
int CountSubsequences(int index, vector<int>& arr, vector<int>& current, int targetSum, int currentSum) {
    if (index == arr.size()) {
        if (currentSum == targetSum) {
            return 1; // Found one valid subsequence
        } 
        return 0; // No valid subsequence found
    }
        
    // Include the current element
    current.push_back(arr[index]);
    int l = CountSubsequences(index + 1, arr, current, targetSum, currentSum + arr[index]);

    // Exclude the current element
    current.pop_back();
    int r = CountSubsequences(index + 1, arr, current, targetSum, currentSum);
    return l+r; 
}

int main() {
    vector<int> arr = {1, 2, 1};
    int targetSum = 2;
    vector<int> current;

    cout << "Subsequences with sum equal to " << targetSum << ":\n";
    findSubsequences(0, arr, current, targetSum, 0);

    cout << "One subsequence with sum equal to " << targetSum << ":\n";
    findOneSubsequences(0, arr, current, targetSum, 0); 
    
    cout << "Count of subsequences with sum equal to " << targetSum << ":\n";
    int count = CountSubsequences(0, arr, current, targetSum, 0);
    cout << "Total count: " << count << endl;

    return 0;
}

//time: O(2^n) for generating all subsequences
//space: O(n) for the recursion stack and current subsequence storage

//Note: This structure of recursive calls and backtracking forms the basis for 
//Dynamic Programming approaches to similar problems, where memoization can be applied.