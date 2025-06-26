//Given two strings s and t of lengths m and n respectively, return 
//the minimum window substring of s such that every character in t (including duplicates) is 
//included in the window. If there is no such substring, return the empty string "".
#include<bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (t.empty() || s.empty()) return "";
    unordered_map<char, int> m;
    for (char c : t) m[c]++;

    int required = t.size(), start = 0, minLen = INT_MAX;
    int i = 0;

    for (int end = 0; end < s.size(); ++end) {
        if (m[s[end]]-- > 0) required--;

        while (required == 0) {
            if (end - i + 1 < minLen) {
                minLen = end - i + 1;
                start = i;
            }
            if (++m[s[i]] > 0) required++;
            i++;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string result = minWindow(s,t);
    cout<<result<<endl;
    return 0;
}

//time:O(s+t)
//space:O(t)