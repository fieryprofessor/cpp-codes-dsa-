//You are given the root of a Binary Search Tree (BST) and a key x.
//The task is to find the ceil of x in the BST.
//The ceil of a key x in the BST is defined as the smallest node value in the 
//BST that is greater than or equal to x.
//If no such value exists, return -1.

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

int findCeil(TreeNode*root, int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }
        if(key > root->val){
            root = root->right;
        }
        else{
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);
    root->left->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(2);
    root->left->right->right = new TreeNode(9);
    int key = 8;
    cout<<"Ceil of "<<key<<" in the BST is: "<<findCeil(root, key)<<endl;
    return 0;
}

//time: O(h) where h is the height of the tree
//space: O(1)