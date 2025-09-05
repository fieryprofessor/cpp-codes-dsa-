//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes 
//in the tree.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor 
//is defined between two nodes p and q as the lowest node in T that has both p 
//and q as descendants (where we allow a node to be a descendant of itself).”

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        //result
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root; //both left and right are not null, we found our result.
        }
    }

int main(){
    TreeNode* root=new TreeNode(1);
    root->left =new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(8);
    root->right->right=new TreeNode(9);
    root->left->right->left=new TreeNode(6);
    root->left->right->right=new TreeNode(7);
    TreeNode* p=root->left->left; //4
    TreeNode* q=root->left->right->right; //7
    TreeNode* lca=lowestCommonAncestor(root,p,q);
    cout<<lca->val;
    return 0;
}

//time: O(N) where N is the number of nodes in the binary tree.
//space: O(H) where H is the height of the binary tree.