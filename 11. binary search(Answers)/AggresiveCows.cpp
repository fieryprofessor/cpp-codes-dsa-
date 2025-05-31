//we need to place the cows in the array position in such a way that the minimum distance
// between any two cows is the maximum.
#include<bits/stdc++.h>
using namespace std;
bool canPlace(vector<int>nums,int dis, int cows){
    int countCows=1;
    int LastCow = nums[0];
    for(int i=1;i<nums.size()-1;i++){
        if(nums[i]-LastCow>=dis){
            countCows++;
            LastCow = nums[i];
        }
    }
    if(countCows>=cows)
    return true;
    else
    return false;
}

int AggresiveCows(vector<int>nums, int cows){
    int n = nums.size();
    int low = 1;
    int high = nums[n-1]-nums[0];
    int distance = 0;
    while(low<=high){
        int mid = low+((high-low)/2);
        if(canPlace(nums,mid,cows)){
            distance = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
}

int main(){
    vector<int>nums = {0,3,4,7,10,9};
    int cows = 4;
    sort(nums.begin(),nums.end());
    int distance = AggresiveCows(nums,cows);
    cout<<distance<<endl;
    return 0;
}

//time:O(nlog(MaxElement-MinElement))
//space:O(1)