//Given an array of integers arr, find the sum of min(b), where b ranges over every
//(contiguous)subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.
#include<bits/stdc++.h>
using namespace std;

vector<int>findNSE(vector<int>&arr){
        int n = arr.size();
        vector<int>nse(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
            st.pop();
            nse[i] = st.empty()? n:st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int>findPSE(vector<int>&arr){
        int n = arr.size();
        vector<int>pse(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
            st.pop();
            pse[i] = st.empty()? -1:st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse = findNSE(arr);
        vector<int>pse = findPSE(arr);
        int total =0;
        int mod = (int)(1e9+7);
        for(int i=0;i<n;i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total+(right*left*1LL*arr[i])%mod)%mod;
        }
        return total;
    }

int main() {
    vector<int> arr = {3,1,2,4};
    cout << "Sum of subarray minimums: " << sumSubarrayMins(arr) << endl;
    return 0;
}

//time: O(5n)
//space: O(5n)