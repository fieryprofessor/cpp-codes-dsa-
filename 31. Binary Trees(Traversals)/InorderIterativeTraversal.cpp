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

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while (true) {
            if (node != nullptr) {
                st.push(node);
                node = node->left;   // move left
            } else {
                if (st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val); // visit node
                node = node->right;           // move right
            }
        }

        return inorder;
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
//space: O(N)  (for the stack)