//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
//determine if the input string is valid.
//An input string is valid if:
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.

#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
        stack <char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{'))
                continue;
                else
                return false;
            }
        }
        return st.empty();
    }

int main() {
    string s = "()[]{}";
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    return 0;
}

//time: O(n)
//space: O(n) for stack