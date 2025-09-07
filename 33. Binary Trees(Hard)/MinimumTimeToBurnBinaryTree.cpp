// You are given the root of a binary tree and an integer target representing a 
// node in the tree where a fire starts.
// At time = 0, the target node catches fire.
// Every second, the fire spreads from any burning node to its left child, 
// right child, and parent node (if they exist).
// Your task is to determine the minimum time required
// to burn the entire binary tree.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BFS to map parents and return target node
TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int start) {
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* res = nullptr;

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node->val == start) res = node;

        if (node->left) {
            parent[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            q.push(node->right);
        }
    }
    return res;
}

// BFS to simulate fire spreading and compute time
int findMaxDistance(unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target) {
    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*, bool> vis;
    vis[target] = true;

    int time = 0;
    while (!q.empty()) {
        int sz = q.size();
        bool burned = false;

        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left && !vis[node->left]) {
                burned = true;
                vis[node->left] = true;
                q.push(node->left);
            }
            if (node->right && !vis[node->right]) {
                burned = true;
                vis[node->right] = true;
                q.push(node->right);
            }
            if (parent[node] && !vis[parent[node]]) {
                burned = true;
                vis[parent[node]] = true;
                q.push(parent[node]);
            }
        }
        if (burned) time++;
    }
    return time;
}

int timeToBurnTree(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* target = bfsToMapParents(root, parent, start);
    return findMaxDistance(parent, target);
}

// Example usage
int main() {
    /*
            1
           / \
          2   3
         /   / \
        4   5   6
       /
      7
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    int start = 2;
    cout << "Minimum time to burn the tree = " << timeToBurnTree(root, start) << endl;

    return 0;
}
