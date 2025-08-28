//Given a string s containing only three types of characters: '(', ')' and 
//'*', return true if s is valid.
//The following rules define a valid string:
//Any left parenthesis '(' must have a corresponding right parenthesis ')'.
//Any right parenthesis ')' must have a corresponding left parenthesis '('.
//Left parenthesis '(' must go before the corresponding right parenthesis ')'.
//'*' could be treated as a single right parenthesis ')' or a single 
//left parenthesis '(' or an empty string "".
#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
        int minR = 0, maxR = 0;
        for(char c : s) {
            if(c == '(') {
                minR++;
                maxR++;
            }
            else if(c == ')') {
                minR--;
                maxR--;
            }
            else { // '*'
                minR--;      // treat as ')'
                maxR++;      // treat as '('
            }
            if(maxR < 0) return false;  // too many ')'
            if(minR < 0) minR = 0;      // clamp
        }
        return minR == 0;
    }

int main(){
    string s = "(*))";
    bool res = checkValidString(s);
    cout<<res<<endl;
    return 0;
}

//time:O(n)
//space:O(1)