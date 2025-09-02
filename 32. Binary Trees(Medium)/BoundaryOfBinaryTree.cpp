//Given the root of a binary tree, return the values of its boundary in 
//anti-clockwise direction starting from the root.

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

bool isLeaf(TreeNode* node){
    if(node->left==NULL && node->right==NULL)
    return true;
    return false;
}

void addLeft(TreeNode* node, vector<int> &res){
    TreeNode* curr = node->left;
    while(curr){
        if(!isLeaf(curr))
        res.push_back(curr->val);
        if(curr->left)
        curr=curr->left;
        else
        curr=curr->right;
    }
}

void addRight(TreeNode* node, vector<int> &res){
    vector<int> temp;
    TreeNode* curr = node->right;
    while(curr){
        if(!isLeaf(curr))
        temp.push_back(curr->val);
        if(curr->right)
        curr=curr->right;   
        else
        curr=curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
    res.push_back(temp[i]);
}
void addLeaves(TreeNode* node, vector<int> &res){
    if(isLeaf(node)){
        res.push_back(node->val);
        return;
    }   
    if(node->left)
    addLeaves(node->left,res);
    if(node->right)
    addLeaves(node->right,res);
}

vector<int> boundaryOfBinaryTree(TreeNode* root) {
    vector<int> res;
    if(root==NULL)
    return res;
    if(!isLeaf(root))
    res.push_back(root->val);
    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);
    return res;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(8);
    root->right->left=new TreeNode(6);
    vector<int> res=boundaryOfBinaryTree(root);
    for(auto i:res)
    cout<<i<<" ";
    return 0;
}

//time:O(n)
//space:O(h)