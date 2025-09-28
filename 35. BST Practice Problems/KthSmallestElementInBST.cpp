//Given the root of a binary search tree, and an integer k,
//return the kth smallest element in the tree.

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

void inorder(TreeNode* root, int &k, int &ans){
    if(!root) return;
    inorder(root->left,k,ans);
    k--;
    if(k==0){
        ans = root->val;
        return;
    }
    inorder(root->right,k,ans);
}

int kthSmallest(TreeNode* root, int k){
    int ans = -1;
    inorder(root,k,ans);
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->left->left->right = new TreeNode(2);
    int k = 3;
    cout<<k<<"th smallest element in the BST is "<<kthSmallest(root,k)<<endl;
    return 0;
}

//time: O(h+k) where h is the height of the tree
//space: O(h) where h is the height of the tree due to recursion stack

//Note: if we want kth largest element then we can do reverse inorder traversal.