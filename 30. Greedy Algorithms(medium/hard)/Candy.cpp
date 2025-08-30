//There are n children standing in a line. Each child is assigned a rating 
//value given in the integer array ratings.
//You are giving candies to these children subjected to the following 
//requirements:
//Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the 
//candies to the children.
#include <bits/stdc++.h>
using namespace std;

int candy(vector<int>& ratings) {
        int n = ratings.size();
        int sum =1; int i=1;
        while(i<n){
            if(ratings[i]==ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak =1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak++;
                sum+=peak;
                i++;
            }
            int down =1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum+=down;
                i++;
                down++;
            }
            if(down>peak)
            sum += down - peak;
        }
        return sum;
    }

int main() {
    vector<int> ratings = {1,0,2};
    cout<<candy(ratings);
    return 0;
}

//time: O(n)
//space: O(1)