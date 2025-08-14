//At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy 
//from you and order one at a time (in the order specified by bills). Each customer will 
//only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the
//correct change to each customer so that the net transaction is that the customer pays $5.
//Note that you do not have any change in hand at first.
//Given an integer array bills where bills[i] is the bill the ith customer pays, return true 
//if you can provide every customer with the correct change, or false otherwise.
#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
        int five=0, ten=0;
        int n = bills.size();
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(five && ten){
                    five--;
                    ten--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }

int main() {
    vector<int> bills = {5, 5, 5, 10, 20};
    if (lemonadeChange(bills)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

//time: O(n)
//space: O(1)