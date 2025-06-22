//You are visiting a farm that has a single row of fruit trees arranged from 
//left to right. The trees are represented by an integer array fruits where 
//fruits[i] is the type of fruit the ith tree produces.
//You want to collect as much fruit as possible. However, the owner has some strict 
//rules that you must follow:
//You only have two baskets, and each basket can only hold a single type of fruit. 
//There is no limit on the amount of fruit each basket can hold.
//Starting from any tree of your choice, you must pick exactly one fruit 
//from every tree (including the start tree) while moving to the right. 
//The picked fruits must fit in one of your baskets.
//Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
//Given the integer array fruits, return the maximum number of fruits you can pick.
#include<bits/stdc++.h>
using namespace std;

int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> basket;
    int left = 0, maxLen =0;
    for(int right = 0;right < fruits.size(); right++){
        basket[fruits[right]]++;
        while(basket.size()>2){
            basket[fruits[left]]--;
            if (basket[fruits[left]] == 0)
            basket.erase(fruits[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main(){
    vector<int> fruits = {1,2,3,2,2};
    int length = totalFruit(fruits);
    cout<<length<<endl;
    return 0;
}

//time:O(n)
//space:(1)