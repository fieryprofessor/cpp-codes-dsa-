//The Children Sum Property problem is defined as follows: A binary tree is 
//said to satisfy the children sum property if, for every non-leaf node, 
//the value of the node is equal to the sum of the values of its left and 
//right children, where a missing child is considered to have value 0. 
//Given the root of a binary tree, the task is either to check whether the 
//tree satisfies this property for all nodes, or to convert the tree so that
//it satisfies the property by only incrementing node values without 
//decreasing or reordering them.

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

void changeTree(TreeNode* root) {
    //base case
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    int child=0;
    if(root->left){
        child+=root->left->val;
    }
    if(root->right){
        child+=root->right->val;
    }
    //if child is greater than parent, then update parent
    if(child>=root->val){
        root->val=child;
    }
    else{
        //if parent is greater than child, then update child
        if(root->left){
            root->left->val=root->val;
        }
        if(root->right){
            root->right->val=root->val;
        }
    }
    //recur for left and right subtree
    changeTree(root->left);
    changeTree(root->right);
    //after returning from recursion, update the parent value
    int total=0;
    if(root->left){
        total+=root->left->val;
    }
    if(root->right){
        total+=root->right->val;
    }
    //if it is not a leaf node, then only update the parent value
    if(root->left || root->right){
        root->val=total;
    }
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);

    changeTree(root);

    // Function to print inorder traversal of the tree
    function<void(TreeNode*)> inorder = [&](TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    };

    inorder(root); // Output the modified tree

    return 0;
}

//time: O(n)
//space: O(h) where h is the height of the tree due to recursion stack