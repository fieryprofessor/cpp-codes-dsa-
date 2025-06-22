//Given a string s and an integer k, return the length of the longest
//substring that contains at most k distinct characters.
#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k){
    if (k == 0 || s.empty()) return 0;

    unordered_map<char, int> freq;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.length(); right++) {
        freq[s[right]]++;

        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0)
            freq.erase(s[left]);
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main(){
    string s = "eceba";
    int k = 2;
    int length = lengthOfLongestSubstringKDistinct(s,k);
    cout<<length<<endl;
    return 0;
}

//time:O(n)
//space:O(k) k = no. of distinct characters.