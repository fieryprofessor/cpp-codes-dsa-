//Given a string s, find the length of the longest substring without duplicate characters.
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int start = 0, maxLen = 0;
        for (int end = 0; end < s.length(); end++) {
            char c = s[end];
            if (lastSeen.count(c) && lastSeen[c] >= start) {
                start = lastSeen[c] + 1;
            }
            lastSeen[c] = end;
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }

int main(){
    string s = "abcabcbb";
    int maxL = lengthOfLongestSubstring(s);
    cout<<maxL<<endl;
    return 0;
}

//time:O(n)
//sapce:O(k) k = size of distinct characters
