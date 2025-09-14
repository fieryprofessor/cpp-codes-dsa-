//Given two integer arrays inorder and postorder where inorder is the inorder 
//traversal of a binary tree and postorder is the postorder traversal of the same 
//tree, construct and return the binary tree.

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

TreeNode* buildTreePostIn(vector<int>&inorder, int is, int ie, vector<int>&postorder, int ps, int pe, map<int,int>&hm){
    if(ps>pe || is>ie) return NULL;
    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;
    root->left = buildTreePostIn(inorder,is,inRoot-1,postorder,ps,ps+numsLeft-1,hm);
    root->right = buildTreePostIn(inorder,inRoot+1,ie,postorder,ps+numsLeft,pe-1,hm);
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        map<int,int>hm;
        for(int i=0;i<inorder.size();++i)
            hm[inorder[i]] = i;
        return buildTreePostIn(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,hm);
    }

int main(){
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = buildTree(inorder,postorder);
    cout<<root->val;
    return 0;
}

//time: O(n)
//space: O(n)

  