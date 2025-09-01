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

vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (root == nullptr) return preorder;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            preorder.push_back(node->val);

            // Push right first so that left is processed first
            if (node->right != nullptr) st.push(node->right);
            if (node->left != nullptr) st.push(node->left);
        }

        return preorder;
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
//space: O(N)  (for the stack)
