//Given the root of a binary tree, check whether it is a mirror of itself 
//(i.e., symmetric around its center).

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

bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left==NULL || right==NULL)
        return left==right;
    if(left->val!=right->val)
        return false;
    return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    return root==NULL || isSymmetricHelp(root->left, root->right);
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);
    cout<<isSymmetric(root);
    return 0;
}

//time:O(n)
//space:O(h)
