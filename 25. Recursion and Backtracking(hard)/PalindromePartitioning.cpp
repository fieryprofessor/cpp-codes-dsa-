//Given a string s, partition s such that every substring of the partition is a palindrome.
//Return all possible palindrome partitioning of s.
#include <bits/stdc++.h>
using namespace std;

// Check if a substring is a palindrome
bool isPalindrome(string s, int start, int end) {
    while (start <= end) {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}

// Backtracking function to generate all palindromic partitions
void func(int index, string s, vector<string>& path, vector<vector<string>>& res) {
    if (index == s.size()) {
        res.push_back(path); // valid partition
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        if (isPalindrome(s, index, i)) {
            path.push_back(s.substr(index, i - index + 1));  // choose
            func(i + 1, s, path, res);                        // explore
            path.pop_back();                                  // unchoose (backtrack)
        }
    }
}

// Wrapper function that initializes data and starts the recursion
vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    vector<vector<string>> result = partition(s);

    for (const auto& group : result) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

//time: O(2^n) in the worst case, where n is the length of the string.
//space: O(n) for the recursion stack and O(n^2) for storing the results in the worst case.