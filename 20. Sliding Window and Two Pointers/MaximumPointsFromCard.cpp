//There are several cards arranged in a row, and each card has an associated 
//number of points. The points are given in the integer array cardPoints.
//In one step, you can take one card from the beginning or from the end of the row.
// You have to take exactly k cards.
//Your score is the sum of the points of the cards you have taken.
//Given the integer array cardPoints and the integer k, 
//return the maximum score you can obtain.
#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;

        for (int i=0;i<k;i++) {
            total += cardPoints[i];
        }
        int maxScore = total;

        for (int i=0;i<k;i++) {
            total -= cardPoints[k-1-i]; 
            total += cardPoints[n-1-i];         
            maxScore = max(maxScore, total);
        }

        return maxScore;
    }

int main(){
    vector<int> v = {1,2,3,4,5,6,1};
    int k=3;
    int maxS = maxScore(v,k);
    cout<<maxS<<endl;
    return 0;
}

//time:O(k) k = number of cards to be picked.
//space:O(1)