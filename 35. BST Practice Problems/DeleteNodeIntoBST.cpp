//Given a node and a BST , delete the node in the BST and return the root of 
//the BST after insertion.

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

TreeNode* findLastRight(TreeNode* root){
        if(root->right==NULL){
            return root;
        }
        return findLastRight(root->right);
    }

TreeNode* helper(TreeNode* root){
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode* dummy = root;
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root= root->right;
                }
            }
        }
        return dummy;
    }

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);
    int key = 3;
    TreeNode* newRoot = deleteNode(root, key);
    cout<<"New root after deletion is: "<<newRoot->val<<endl;
    return 0;
}

//time: O(h) where h is the height of the tree
//space: O(1)
    

    