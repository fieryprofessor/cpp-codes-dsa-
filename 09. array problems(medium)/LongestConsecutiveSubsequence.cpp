//Find the longest consecutive subsequence in the array.
#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(vector<int>&v){
    sort(v.begin(),v.end());
    int count = 1;
    int maxLength = 1;
    int prevSmallest = INT_MIN;
    int current = v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]==current){
            continue;
        }
        else if(v[i]==current+1){
            count++;
            maxLength= max(maxLength,count);
            prevSmallest = current;
            current = v[i];
        }
        else{
            count=1;
            current = v[i];
        }
    }
    return maxLength;
}
//time: O(nlogn)
//space: O(1)

int LCSHashing(vector<int>&v){
    unordered_set<int>s;
    for(int i=0;i<v.size();i++){
        s.insert(v[i]);
    }

    int maxLength = 1;
    for(auto it : s){
        if(s.find(it-1)==s.end()){
            int count=1;
            int x = it;
            while(s.find(x+1)!=s.end()){
                x=x+1;
                count++;
            }
            maxLength= max(maxLength,count);
        }
    }
    return maxLength;
}
//time: O(nlogn)
//space: Θ(n) or O(n^2)

int main(){
    vector<int>v={1,1,1,2,2,2,3,3,4,100,100,101,101,102};
    int length1 = longestCommonSubsequence(v);
    cout<<length1<<endl;
    int length2 = LCSHashing(v);
    cout<<length2<<endl;
    return 0;
}