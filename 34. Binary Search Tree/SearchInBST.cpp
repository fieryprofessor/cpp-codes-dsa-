//You are given the root of a binary search tree (BST) and an integer val.
//Find the node in the BST that the node's value equals val and return the subtree 
//rooted with that node. If such a node does not exist, return null.

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* searchBST(TreeNode* root, int val){
    while(root!=NULL && root->val!=val){
        root = val<root->val?root->left:root->right;
    }
    return root;
}

int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->left->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(13);
    int val = 10;
    TreeNode* ans = searchBST(root,val);
    if(ans!=NULL) 
    cout<<ans->val;
    else 
    cout<<"NULL";
    return 0;
}

//time: O(h) where h is the height of the tree 
//(logn for balanced tree and n for skewed tree)
//space: O(1)