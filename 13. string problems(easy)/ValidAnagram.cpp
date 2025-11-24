//Given two strings s and t, return true if t is an anagram of s,
//and false otherwise.
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        for(auto c: s) freq[c-'a']++;
        for(auto c: t) freq[c-'a']--;
        for(auto i :freq)
            if(i!=0) return false;
        return true;
    }

int main(){
    string s = "anagram";
    string t = "nagaram";
    bool ans = isAnagram(s,t);
    cout<<ans<<endl;
    return 0;
}

//time: O(n+m) where n and m are length of the both the strings.
//space: O(1)

