//Given n items with specific values and weights, and a knapsack with maximum weight capacity W,
//determine the maximum value that can be obtained by taking whole or fractional parts of items
//such that the total weight does not exceed W.
#include<bits/stdc++.h>
using namespace std;

double FractionalKnapsack(vector<pair<int,int>>& items, int W) {
    // Sort items by value-to-weight ratio in descending order
    sort(items.begin(), items.end(), [](pair<int,int> a, pair<int,int> b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    });

    double totalValue = 0.0; // To store the total value of the knapsack
    for (auto& item : items) {
        if (W <= 0) break; // If the knapsack is full, break out of the loop

        int weight = item.second;
        int value = item.first;

        if (weight <= W) {
            // If the whole item can be taken
            totalValue += value;
            W -= weight;
        } else {
            // Take the fraction of the item that fits in the knapsack
            totalValue += value * ((double)W / weight);
            W = 0; // Knapsack is now full
        }
    }
    return totalValue; // Return the maximum value 
}

int main(){
    vector<pair<int,int>> items={{100,20},{60,10},{100,50},{200,50}}; // pair of (value, weight)
    int W = 90; // maximum weight capacity
    double result = FractionalKnapsack(items, W);
    cout << "Maximum value in Knapsack = " << result << endl;
    return 0;
}

//time: O(n log n) for sorting + O(n) for iterating through items
//space: O(1) for the algorithm