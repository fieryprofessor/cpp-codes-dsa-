//You are given the root of a Binary Search Tree (BST) and a key x.
//The task is to find the floor of x in the BST.
//The floor of a key x in the BST is defined as the largest node value in the BST 
//that is less than or equal to x.
//If no such value exists, return -1.

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

int findFloor(TreeNode*root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }
        if(key < root->val){
            root = root->left;
        }
        else{
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(17);
    root->right->left = new TreeNode(13);
    root->left->right->left = new TreeNode(6);
    int key = 9;
    cout<<"Floor of "<<key<<" in the BST is: "<<findFloor(root, key)<<endl;
    return 0;
}

//time: O(h) where h is the height of the tree
//space: O(1)