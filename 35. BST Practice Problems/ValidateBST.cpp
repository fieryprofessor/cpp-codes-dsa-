//Given a root of a binary tree, determine if it is a valid binary search tree
// (BST).

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

bool isValidBST(TreeNode* root, long minVal, long maxVal){
        if(root==NULL) return true;
        if(root->val>=maxVal || root->val<=minVal) return false;
        return isValidBST(root->left,minVal,root->val) && isValidBST(root->right,root->val,maxVal);
    }

bool isValidBST(TreeNode* root) {
        return isValidBST(root,LONG_MIN,LONG_MAX);
    }

int main(){
    TreeNode* root = new TreeNode(13);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(12);
    root->right->right = new TreeNode(17);
    root->right->left = new TreeNode(14);
    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(8);
    root->right->right->left = new TreeNode(16);
    if(isValidBST(root))
     cout<<"Valid BST"<<endl;
    else
     cout<<"Invalid BST"<<endl;
    return 0;
}

//time: O(n) where n is the number of nodes in the tree
//space: O(h) where h is the height of the tree due to recursion stack