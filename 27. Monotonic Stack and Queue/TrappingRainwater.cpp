//Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it can trap after raining.
#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
        int n = height.size();
        int lMax=0, rMax =0, total =0, l =0, r =n-1;
        while(l<r){
            if(height[l]<=height[r]){
                if(lMax>height[l])
                total += lMax - height[l];
                else
                lMax = height[l];
                l++;
            }
            else{
                if(rMax>height[r])
                total += rMax - height[r];
                else
                rMax = height[r];
                r--;
            }
        }
        return total;
    }

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped rainwater: " << trap(height) << endl;
    return 0;
}

//time: O(n)
//space: O(1)