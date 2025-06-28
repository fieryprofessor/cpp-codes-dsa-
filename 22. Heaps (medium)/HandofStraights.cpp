// /Alice has some number of cards and she wants to rearrange the cards into 
//groups so that each group is of size groupSize, and consists of groupSize 
//consecutive cards.Given an integer array hand where hand[i] is the value 
//written on the ith card and an integer groupSize, return true if she can 
//rearrange the cards, or false otherwise.
#include<bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) 
        return false;

        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& entry : freq) {
            minHeap.push(entry.first);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();
            for (int i = 0; i < groupSize; ++i) {
                int curr = start + i;
                if (freq[curr] == 0)
                return false;
                freq[curr]--;

                if (freq[curr] == 0 && curr == minHeap.top()) {
                    minHeap.pop();
                }
            }
        }
            return true;
    }

int main(){
    vector<int>hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    bool answer = isNStraightHand(hand,groupSize);
    cout<<answer<<endl;
    return 0;
}

//k = number of unique card values
//time:O(n log k)
//space:O(k)