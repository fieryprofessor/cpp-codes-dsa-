//Given the root of a complete binary tree, return the number of the nodes in 
//the tree. According to Wikipedia, every level, except possibly the last, is 
//completely filled in a complete binary tree, and all nodes in the last level
//are as far left as possible. It can have between 1 and 2h nodes inclusive at
//the last level h. Design an algorithm that runs in less than O(n) time 
//complexity.

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

int findHeightLeft(TreeNode* node){
    int h = 0;
    while(node){
        h++;
        node = node->left;
    }
    return h;
}
int findHeightRight(TreeNode* node){
    int h = 0;
    while(node){
        h++;
        node = node->right;
    }
    return h;
}

int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout<<countNodes(root);
    return 0;
}

//time: O((logn)^2)
//space: O(1)