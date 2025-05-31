//A conveyor belt has packages that must be shipped from one port to another within days days.
//The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the 
//ship with packages on the conveyor belt (in the order given by weights). We may not load 
//more weight than the maximum weight capacity of the ship.
//Return the least weight capacity of the ship that will result in all the packages on 
//the conveyor belt being shipped within days days.
#include<bits/stdc++.h>
using namespace std;

int isDays(int capacity, vector<int>weights){
        int days =0;
        int sum=0;
        for(int ele :weights){
           sum+=ele;
           if(sum>capacity){
            sum=0;
            days++;
            sum+=ele;
           }
        }
        if(sum>0)
        days++;
        
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int sum = accumulate(weights.begin(),weights.end(),0);
        int maxEle = *max_element(weights.begin(),weights.end());
        int low=maxEle;
        int high = sum;
        int weight = -1;
         while(low<=high){
            int mid= low+((high-low)/2);
            if(isDays(mid,weights)<=days){
                weight = mid;
                high = mid-1;
            }else{
                low=mid+1;
            }
        }
        return weight;
    }

int main(){
    vector<int>weights = {1,2,3,4,5,6,7,8,9,10};
    int days =5;
    int capacity = shipWithinDays(weights,days);
    cout<<capacity<<endl;
    return 0;
}

//time:O(nlog(sum-maxElement))
//space:O(1)
