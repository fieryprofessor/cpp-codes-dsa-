//Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
//The guards have gone and will come back in h hours.
//Koko can decide her bananas-per-hour eating speed of k. Each hour,
//she chooses some pile of bananas and eats k bananas from that pile. 
//If the pile has less than k bananas, she eats all of them instead and will not eat
//any more bananas during this hour.
//Koko likes to eat slowly but still wants to finish eating all the bananas before
//the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.
#include<bits/stdc++.h>
using namespace std;

 long long timeTaken(vector<int> piles, int mid){
        long long time=0;
        for(int ele: piles){
            if(ele%mid==0)
            time+=ele/mid;
            else
            time+=((ele/mid)+1);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxEle = *max_element(piles.begin(),piles.end());
        int n = piles.size();
        int low = 1;
        int high = maxEle;
        int k=-1;
        while(low<=high){
            int mid = low+((high-low)/2);
            if(timeTaken(piles,mid)<=h){
                k=mid;
                high=mid-1;
            }else{
                low = mid+1;
            }
        }
        return k;
    }

    int main(){
        vector<int>piles={3,6,7,11};
        int h=8;
        int k = minEatingSpeed(piles,h);
        cout<<k<<endl;
        return 0;
    }