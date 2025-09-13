//Given two integer arrays preorder and inorder where preorder is the preorder
//traversal of a binary tree and inorder is the inorder traversal of the 
//same tree, construct and return the binary tree.

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

TreeNode* buildTree(vector<int>&preorder,int preStart,int preEnd, vector<int>&inorder, int inStart,int inEnd,map<int,int>&inMap){
    if(preStart>preEnd || inStart>inEnd) return NULL;
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    root->left = buildTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
    root->right = buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,inMap);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        TreeNode* root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inMap);
        return root;
    }

int main(){
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = buildTree(preorder,inorder);
    cout<<root->val;
    return 0;
}

//time: O(n)
//space: O(n)