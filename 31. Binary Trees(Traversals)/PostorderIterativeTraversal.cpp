//Given the root of a binary tree, return the postorder traversal of its nodes' values.

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

vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == nullptr) return postorder;

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);

            if (node->left != nullptr) st1.push(node->left);
            if (node->right != nullptr) st1.push(node->right);
        }

        while (!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }

int main(){
    TreeNode* root=new TreeNode(1);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(3);
    vector<int>ans=postorderTraversal(root);
    for(auto i:ans)
        cout<<i<<" ";
    return 0;
}

//time: O(N)
//space: O(N)  (for the stacks)

