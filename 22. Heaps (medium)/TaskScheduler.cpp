//You are given an array of CPU tasks, each labeled with a letter from A to Z,
//and a number n. Each CPU interval can be idle or allow the completion of one task.
//Tasks can be completed in any order, but there's a constraint: there has to be a
//gap of at least n intervals between two tasks with the same label.
//Return the minimum number of CPU intervals required to complete all tasks.
#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> freq(26, 0);
    for (char task : tasks) freq[task - 'A']++;

    int maxFreq = *max_element(freq.begin(), freq.end());
    int maxCount = count(freq.begin(), freq.end(), maxFreq);

    return max((int)tasks.size(), (maxFreq - 1) * (n + 1) + maxCount);
}

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    int time = leastInterval(tasks,n);
    cout<<time<<endl;
    return 0;
}

//time:O(n)
//space:O(1)