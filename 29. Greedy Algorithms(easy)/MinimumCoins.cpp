//You are given an array of Indian coin denominations and a target amount V. Using an 
//unlimited supply of each coin, determine the minimum number of coins required to make 
//exactly V. You must use a greedy approach, always picking the largest possible 
//denomination first.
#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int amount){
    int deno[] = {1,2,5,10,20,50,100,200,500,1000};
    int n = sizeof(deno)/sizeof(deno[0]);

    int count = 0; // To count the number of coins used
    for (int i = n - 1; i >= 0 && amount > 0; i--) {
        while (amount >= deno[i]) {
            amount -= deno[i]; // Subtract the denomination from the amount
            count++; // Increment the coin count
        }
    }
    return count; // Return the total number of coins used
}

int main(){
    int amount = 49;
    int coins = minimumCoins(amount);
    cout<< "Minimum coins required: " << coins << endl;
    return 0;
}

//time: O(n) for iterating through denominations
//space: O(1) for the algorithm