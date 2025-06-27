//Check if the given array is min-heap or not.
#include<bits/stdc++.h>
using namespace std;

bool heapChecker(vector<int> &nums){
    int n = nums.size();
    for(int i = 0; i <= (n - 2) / 2; i++){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && nums[i] > nums[left])
            return false;

        if (right < n && nums[i] > nums[right])
            return false;
    }
    return true;
}

int main(){
    vector<int> nums = {10, 20, 5, 30, 15, 25, 40, 50, 35, 45, 60, 55};
    bool answer1 = heapChecker(nums);
    cout<<answer1<<endl;

    vector<int> nums2 = {1, 3, 5, 7, 9, 6, 8, 10, 11, 13, 12, 15};
    bool answer2 = heapChecker(nums2);
    cout<<answer2<<endl;

    return 0;
}

//time:O(n)
//space:O(1)