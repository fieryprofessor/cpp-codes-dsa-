//A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are 
//valid parentheses strings, and + represents string concatenation.
//For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
//A valid parentheses string s is primitive if it is nonempty, and there does not exist 
//a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
//Given a valid parentheses string s, consider its primitive decomposition: 
//s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
//Return s after removing the outermost parentheses of every primitive string in 
//the primitive decomposition of s.
#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;

        for (char c : s) {
            if (c == '(') {
                if (depth > 0) result += c;
                depth++;
            } else {
                depth--;
                if (depth > 0) result += c;
            }
        }
        return result;
    }

int main(){
    string s = "(()())(())";
    string ans = removeOuterParentheses(s);
    cout<<ans<<endl;
    return 0;
}

//time:O(n)
//space:O(n) output string