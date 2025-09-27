//Given a node and a BST , insert the node in the BST and return the root of 
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

TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode *cur = root;
        while(true){
            if(cur->val<=val){
                if(cur->right!=NULL)
                cur = cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left!=NULL)
                cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }

    int main(){
        TreeNode* root = new TreeNode(4);
        root->left = new TreeNode(2);
        root->right = new TreeNode(7);
        root->left->left = new TreeNode(1);
        root->left->right = new TreeNode(3);
        int val = 5;
        root = insertIntoBST(root, val);
        cout<<"Node "<<val<<" inserted into the BST."<<endl;
        return 0;
    }

//time: O(h) where h is the height of the tree
//space: O(1)