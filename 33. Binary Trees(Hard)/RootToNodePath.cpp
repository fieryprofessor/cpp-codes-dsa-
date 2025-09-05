//Given the root of a binary tree and the value of a target node, return the 
//path from the root to that target node as a list of node values.
//If the target node does not exist in the tree, return an empty list.

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

bool getPath(TreeNode* root, vector<int>&arr, int x){
    if(!root)
    return false;

    arr.push_back(root->val);

    if(root->val==x)
    return true;

    if(getPath(root->left,arr,x) || getPath(root->right,arr,x))
    return true;

    arr.pop_back();
    return false;
}

vector<int> solve(TreeNode* A, int B){
    vector<int> arr;
    if(A==NULL){
        return arr;
    }
    getPath(A,arr,B);
    return arr;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    int target=7;
    vector<int> ans=solve(root,target);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}

//time:O(N)
//space:O(H) H is height of tree