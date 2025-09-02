//A path in a binary tree is a sequence of nodes where each pair of adjacent 
//nodes in the sequence has an edge connecting them. A node can only appear in 
//the sequence at most once. Note that the path does not need to pass through 
//the root.
//The path sum of a path is the sum of the node's values in the path.
//Given the root of a binary tree, return the maximum path sum of any non-empty 
//path.

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

int maxPathDown(TreeNode* node, int &maxi){
    if(node==NULL)
    return 0;
    int left = max(0,maxPathDown(node->left,maxi));
    int right = max(0,maxPathDown(node->right,maxi));
    maxi = max(maxi,left+right+node->val);
    return max(left,right)+node->val;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int main(){
    TreeNode* root=new TreeNode(-10);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<maxPathSum(root);
    return 0;
}

//time:O(n)
//space:O(h)