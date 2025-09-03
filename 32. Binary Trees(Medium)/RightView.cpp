//Given the root of a binary tree, imagine yourself standing on the right side 
//of it, return the values of the nodes you can see ordered from top to bottom.

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

void recursion(TreeNode* root, int level, vector<int>&res){
    if(root==NULL)
    return;
    if(res.size()==level)
    res.push_back(root->val);
    recursion(root->right,level+1,res);
    recursion(root->left,level+1,res);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    recursion(root,0,res);
    return res;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(3);
    root->left=new TreeNode(2);
    root->left->right=new TreeNode(5);
    root->left->left=new TreeNode(4);
    root->left->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    vector<int> ans=rightSideView(root);
    for(auto i:ans)
    cout<<i<<" ";
    return 0;
}

//time:O(n)
//space:O(h)