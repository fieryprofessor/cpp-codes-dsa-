//Given string num representing a non-negative integer num, and an integer k, return the 
//smallest possible integer after removing k digits from num.
#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        // Remove remaining k digits from the end
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        // Build the result in correct order
        string res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int idx = 0;
        while (idx < res.size() && res[idx] == '0') idx++;
        res = res.substr(idx);

        return res.empty() ? "0" : res;
    }

int main() {
    string num = "1432219";
    int k = 3;
    cout << removeKdigits(num, k) << endl; 
    return 0;
}

//time: O(n)
//space: O(n)
