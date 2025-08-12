//Assume you are an awesome parent and want to give your children some cookies. But, you should 
//give each child at most one cookie.
//Each child i has a greed factor g[i], which is the minimum size of a cookie that the child 
//will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the 
//cookie j to the child i, and the child i will be content. Your goal is to maximize the number 
//of your content children and output the maximum number.
#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int left=0, right =0;
        while(left<n && right<m){
            if(s[right]>=g[left]){
                left++;
                right++;
            }
            else{
                right++;
            }
        }
        return left;
    }

int main(){
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    cout << findContentChildren(g, s) << endl; 
    return 0;
}

//time: O(nlogn + mlogm)
//space: O(1)