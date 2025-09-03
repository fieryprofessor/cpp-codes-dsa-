//Given the root of a binary tree, print the bottom view of the tree.
//The bottom view of a binary tree is the set of nodes visible when the tree is viewed from
//the bottom.
//For each vertical line (or horizontal distance from the root), only the last node
//encountered from top to bottom should be included in the bottom view.

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

vector<int> bottomView(TreeNode* root) {
    vector<int> ans;
    if(root==NULL)
    return ans;
    map<int,int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        mpp[line] = node->val; 
        if(node->left){
            q.push({node->left,line-1});
        }
        if(node->right){
            q.push({node->right,line+1});
        }
    }
    for(auto i:mpp){
        ans.push_back(i.second);
    }
    return ans;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    vector<int> ans=bottomView(root);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}

//time:O(nlogn)
//space:O(n)
