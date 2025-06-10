//Given an input string s, reverse the order of the words.
//A word is defined as a sequence of non-space characters. 
//The words in s will be separated by at least one space.
//Return a string of the words in reverse order concatenated by a single space.
//Note that s may contain leading or trailing spaces or multiple spaces between two words. 
//The returned string should only have a single space separating the words. 
//Do not include any extra spaces.
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string word;

        while (iss >> word) {
        words.push_back(word);
        }

        reverse(words.begin(),words.end());
        string ans="";
        for(int i=0;i<words.size();i++){
            if (i > 0) 
            ans += " ";
            ans += words[i];
        }
        return ans;
    }

int main(){
    string s = "the sky is blue";
    string ans = reverseWords(s);
    cout<<ans<<endl;
    return 0;
}

//time:O(n)
//space:O(n)