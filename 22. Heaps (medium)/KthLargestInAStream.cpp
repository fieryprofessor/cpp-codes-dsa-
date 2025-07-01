//You are given an integer k and a stream of integers. Implement a class KthLargest
//with:
//KthLargest(int k, int[] nums) — Initializes the object with the integer k and 
//the stream of integers nums.
//int add(int val) — Appends the integer val to the stream and returns the 
//element representing the kth largest element in the stream.
#include <bits/stdc++.h>
using namespace std;

class KthLargest {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }

    int add(int val) {
        if (minHeap.size() < k)
            minHeap.push(val);
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
        return minHeap.top();
    }
};

int main() {
    int k = 3;
    vector<int> stream = {4, 5, 8, 2};
    KthLargest kth(k, stream);

    vector<int> incoming = {3, 5, 10, 9, 4};
    for (int val : incoming) {
        cout << "After inserting " << val << ", Kth largest: " << kth.add(val) << endl;
    }

    return 0;
}

//time:O(log k)
//space:O(k)
