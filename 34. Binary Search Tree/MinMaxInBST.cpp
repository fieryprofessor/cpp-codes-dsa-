//Find the minimum and maximum value in a Binary Search Tree.

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

int findMin(TreeNode* root) {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    TreeNode* curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr->val;
}

int findMax(TreeNode* root) {
    if (!root) {
        throw runtime_error("Tree is empty");
    }
    TreeNode* curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }
    return curr->val;
}

int main() {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(13);

    cout << "Minimum value in BST: " << findMin(root) << endl;
    cout << "Maximum value in BST: " << findMax(root) << endl; 

    return 0;
}

//time: O(h) where h is the height of the tree 
//(logn for balanced tree and n for skewed tree)
//space: O(1)