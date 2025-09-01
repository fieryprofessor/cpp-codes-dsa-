//Given a binary tree, determine if it is height-balanced.

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

int dfsHeight(TreeNode *root){
    if(root==NULL) return 0;

    int lh = dfsHeight(root->left);
    if(lh==-1) return -1;
    int rh = dfsHeight(root->right);
    if(rh==-1) return -1;

    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}

bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1;
    }

int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    cout<<isBalanced(root);
    return 0;
}

//time: O(n)
//space: O(h) h is height of tree