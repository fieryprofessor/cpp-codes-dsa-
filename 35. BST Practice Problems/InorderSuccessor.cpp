//Given the root of a binary search tree and a node p in it, return its inorder
//successor.The inorder successor of a node p is the node with the smallest key greater
//than p.val.If no such node exists, return null.
//Note: Predecessor is also implemented here.

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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;
    while(root!=NULL){
        if(p->val>=root->val){
            root = root->right;
        }else{
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p){
    TreeNode* predecessor = NULL;
    while(root!=NULL){
        if(p->val<=root->val){
            root = root->left;
        }else{
            predecessor = root;
            root = root->right;
        }
    }
    return predecessor;
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);
    TreeNode* p = root->left->right->left; // Node with value 3
    TreeNode* successor = inorderSuccessor(root, p);
    if(successor){
        cout<<"Inorder Successor of node "<<p->val<<" is: "<<successor->val<<endl;
    }else{
        cout<<"Inorder Successor of node "<<p->val<<" does not exist."<<endl;
    }
    p = root->right; // Node with value 7
    TreeNode* predecessor = inorderPredecessor(root, p);
    if(predecessor){
        cout<<"Inorder Predecessor of node "<<p->val<<" is: "<<predecessor->val<<endl;
    }else{
        cout<<"Inorder Predecessor of node "<<p->val<<" does not exist."<<endl;
    }
    return 0;
}

//time: O(h) where h is the height of the tree
//space: O(1)