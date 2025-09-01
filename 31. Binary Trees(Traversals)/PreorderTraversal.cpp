//Given the root of a binary tree, return the preorder traversal of its nodes' values.

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

void preorder(TreeNode* root, vector<int>& ans){
        if (root==nullptr)
            return;

        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }

vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    preorder(root,ans);
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int>ans=preorderTraversal(root);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}   

//time: O(N)
//space: O(N)  (for the recursion stack)

