//You are given a string s and an integer k. You can choose any character of the 
//string and change it to any other uppercase English character. 
//You can perform this operation at most k times.
//Return the length of the longest substring containing the same letter you can 
//get after performing the above operations.
#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> c(26,0);
        int maxLen =0,start =0,result =0;
        for(int end =0;end<n;end++){
            c[s[end]-'A']++;
            maxLen = max(maxLen,c[s[end]-'A']);
            while((end-start+1)-maxLen>k){
                c[s[start]-'A']--;
                start++;
            }

           result = max(result,end - start + 1); 
        }
        return result;
    }

int main(){
    string s = "ABAB";
    int k = 2;
    int length = characterReplacement(s,k);
    cout<<length<<endl;
    return 0;
}

//time:O(n)
//space:O(1)