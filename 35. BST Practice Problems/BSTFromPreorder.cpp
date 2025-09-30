//Given an array of integers preorder, which represents the preorder traversal of a BST
//(i.e., binary search tree), construct the tree and return its root.
//It is guaranteed that there is always possible to find a binary search tree with the
//given requirements for the given test cases.

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

TreeNode* build(vector<int>&A, int &i, int bound){
    if(i==A.size() || A[i]>bound) return NULL;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A,i,root->val);
    root->right = build(A,i,bound);
    return root;
}

TreeNode* bstFromPreorder(vector<int>&A){
    int i=0;
    return build(A,i,INT_MAX);
}

int main(){
    vector<int> A = {8,5,1,7,10,12};
    TreeNode* root = bstFromPreorder(A);
    cout<<"Root of the BST is: "<<root->val<<endl;
    return 0;
}

//time: O(n) where n is the number of nodes in the tree
//space: O(h) where h is the height of the tree due to recursion stackclear
