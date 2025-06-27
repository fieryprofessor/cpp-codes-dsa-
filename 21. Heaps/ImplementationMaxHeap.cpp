//Implementation of max heap using arrays.
#include<bits/stdc++.h>
using namespace std;

//comparing parent and its left and right children and swapping accordingly to
//build the heap.
void heapifyMax(vector<int>& heap, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && heap[l] > heap[largest]) largest = l;
    if (r < n && heap[r] > heap[largest]) largest = r;

    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapifyMax(heap, n, largest);
    }
}

//nodes from n/2 to n-1 are leaf nodes and already a valid heap so no need to 
//build them.
void buildMaxHeap(vector<int>& heap) {
    int n = heap.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        heapifyMax(heap, n, i);
    }
}


int main(){
    vector<int> heap = {
    45, 12, 33, 8, 19, 27, 31, 23, 17, 6};
    buildMaxHeap(heap);
    cout << "Max Heap: ";
    for (int val : heap) cout << val << " ";
    cout << endl;
    return 0;
}

//Building heap takes O(n)
//heapify function takes O(log n)