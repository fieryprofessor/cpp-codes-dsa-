//Serialization is the process of converting a data structure or object into a 
//sequence of bits so that it can be stored in a file or memory buffer, or 
//transmitted across a network connection link to be reconstructed later in the 
//same or another computer environment.
//Design an algorithm to serialize and deserialize a binary tree. There is no 
//restriction on how your serialization/deserialization algorithm should work. 
//You just need to ensure that a binary tree can be serialized to a string and 
//this string can be deserialized to the original tree structure.

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

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root) return "";
    string s = "";
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode = q.front();
        q.pop();
        if(curNode==NULL) 
        s.append("#,");
        else
        s.append(to_string(curNode->val)+',');
        if(curNode!=NULL){
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left = NULL;
        }else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right= NULL;
        }else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(13);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    string data=serialize(root);
    cout<<data<<endl;
    TreeNode* newRoot=deserialize(data);
    cout<<newRoot->val<<endl;
    return 0;
}

//time:O(N)
//space:O(N)


