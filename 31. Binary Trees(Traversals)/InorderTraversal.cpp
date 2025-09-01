//Given the root of a binary tree, return the inorder traversal of its nodes' values.

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

void inorder(TreeNode* root, vector<int>& ans){
        if (root==nullptr)
            return;

        
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>ans;
    inorder(root,ans);
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int>ans=inorderTraversal(root);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

//time: O(N)
//space: O(N)  (for the recursion stack)