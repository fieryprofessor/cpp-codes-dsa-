//Given the root of a binary tree, return the length of the diameter of the tree.
//The diameter of a binary tree is the length of the longest path between any 
//two nodes in a tree. This path may or may not pass through the root.
//The length of a path between two nodes is represented by the number of edges 
//between them.

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



 int height(TreeNode* node, int& diameter){
        if(!node)
        return 0;

        int lh = height(node->left,diameter);
        int rh = height(node->right,diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh,rh);
    }

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root,diameter);
    return diameter;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    cout<<diameterOfBinaryTree(root);
    return 0;
}

//time: O(n)
//space: O(h) h is height of tree