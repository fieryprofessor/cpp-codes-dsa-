//You are given a string num, representing a large integer. Return the largest-valued 
//odd integer (as a string) that is a non-empty substring of num, or an empty 
//string "" if no odd integer exists.
//A substring is a contiguous sequence of characters within a string.
#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string s) {
         int n = s.size();
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==1){
                 string result = s.substr(0,i+1);
                 int pos = result.find_first_not_of('0');
                return (pos == string::npos) ? "" : result.substr(pos);
            }
        }
        return "";
    }

int main(){
    string num = "35427";
    string ans = largestOddNumber(num);
    cout<<ans<<endl;
    return 0;
}

//time:O(n)
//space:O(n)