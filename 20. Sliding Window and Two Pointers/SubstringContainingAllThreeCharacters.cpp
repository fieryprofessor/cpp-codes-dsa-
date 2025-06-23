//Given a string s consisting only of characters a, b and c.
//Return the number of substrings containing at least one occurrence of 
//all these characters a, b and c.
#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
        int n = s.size();
        int start =0;
        long long c = 0;
        unordered_map<int,int> f;
        for(int end =0;end<n;end++){
            f[s[end]]++;

            while (f['a'] > 0 && f['b'] > 0 && f['c'] > 0) {
            c += (n - end);  
            f[s[start]]--;
            start++;
            }
        }
        return c;
}

int main(){
    string s = "abcabc";
    int count = numberOfSubstrings(s);
    cout<<count<<endl;
    return 0;
}

//time:O(n)
//space:O(1)