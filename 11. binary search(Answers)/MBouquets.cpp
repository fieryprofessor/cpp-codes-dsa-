//You are given an integer array bloomDay, an integer m and an integer k.
//You want to make m bouquets. To make a bouquet, you need to use k adjacent 
//flowers from the garden.
//The garden consists of n flowers, the ith flower will bloom in the bloomDay[i]
// and then can be used in exactly one bouquet.
//Return the minimum number of days you need to wait to be able to make m bouquets 
//from the garden. If it is impossible to make m bouquets return -1.
#include<bits/stdc++.h>
using namespace std;

 bool canMake(int day, int m, int k,vector<int>& v){
        int count=0;
        for(int i=0;i<v.size() && m>0;i++){
            if(v[i]<=day){
                count++;
                if(count==k){
                    count=0;
                    m--;
                }
            }else{
                count=0;
            }
        }
        if(m==0)
        return true;
        else
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m>n/k)
        return -1;
        int maxEle = *max_element(bloomDay.begin(),bloomDay.end());
        int days = 0;
        int low = 1;
        int high = maxEle;
        while(low<=high){
            int mid = low+((high-low)/2);
            if(canMake(mid,m,k,bloomDay)){
                days = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return days;
    }

    int main(){
        vector<int>bloomDay = {1,10,3,10,2};
        int m = 3;
        int k = 1;
        int days = minDays(bloomDay,m,k);
        cout<<days<<endl;
        return 0;
    }

    //time:O(nlog(MaxElement))
    //space:O(1)