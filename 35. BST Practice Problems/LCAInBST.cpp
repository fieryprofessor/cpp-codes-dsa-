//Given a binary search tree (BST), find the lowest common ancestor (LCA) node 
//of two given nodes in the BST.

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
        if(root==NULL) return NULL;
        int curr = root->val;
        if(curr<p->val && curr<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr>p->val && curr>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(15);
    root->right->left = new TreeNode(11);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->left->right->left->left = new TreeNode(5);
    root->left->right->left->right = new TreeNode(7);
    TreeNode* p = root->left->right->left->left; // Node with value 5
    TreeNode* q = root->left->right->right; // Node with value 9
    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if(lca)
     cout<<"LCA of "<<p->val<<" and "<<q->val<<" is "<<lca->val<<endl;
    else
     cout<<"LCA not found"<<endl;
    return 0;
}

//time: O(h) where h is the height of the tree
//space: O(h) where h is the height of the tree due to recursion stack