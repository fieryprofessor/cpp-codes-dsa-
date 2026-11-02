#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<int> segTree;
    int n;

    void build(int node, int start, int end, vector<int>& arr) {

        if (start == end) {
            segTree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);

        segTree[node] = segTree[2 * node] +
                        segTree[2 * node + 1];
    }

    int query(int node, int start, int end, int L, int R) {

        if (end < L || start > R) {
            return 0;
        }

        if (L <= start && end <= R) {
            return segTree[node];
        }

        int mid = (start + end) / 2;

        int leftSum = query(2 * node, start, mid, L, R);

        int rightSum = query(2 * node + 1, mid + 1, end, L, R);

        return leftSum + rightSum;
    }

    void update(int node, int start, int end, int idx, int val) {

        if (start == end) {
            segTree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        }
        else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }

        segTree[node] = segTree[2 * node] +
                        segTree[2 * node + 1];
    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);

        build(1, 0, n - 1, arr);
    }

    int rangeQuery(int L, int R) {
        return query(1, 0, n - 1, L, R);
    }

    void pointUpdate(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
};

int main() {

    vector<int> arr = {2, 4, 5, 7, 8, 9, 10, 12};

    SegmentTree st(arr);

    cout << st.rangeQuery(1, 5) << endl;

    st.pointUpdate(3, 15);

    cout << st.rangeQuery(1, 5) << endl;

    cout << st.rangeQuery(0, 7) << endl;

    return 0;
}
