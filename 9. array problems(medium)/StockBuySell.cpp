//What is the maximum profit we can generate by buying and selling the stock.
#include<bits/stdc++.h>
using namespace std;

int stockBuySell(vector<int>&v){
    int mini = v[0];
    int maxProfit = 0;
    for(int i=1;i<v.size();i++){
        int cost = v[i]-mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,v[i]);
    }
    return maxProfit;
}

int main(){
    vector<int>v={7,1,5,3,6,4};
    int maxProfit = stockBuySell(v);
    cout<<maxProfit<<endl;
    return 0;
}
//time: O(n)
//space:O(1)