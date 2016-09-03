// Symmetric Tree
// Given a binary tree, check whether it is a mirror of itself 
// (ie, symmetric around its center).

// For example, this binary tree is symmetric:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// But the following is not:
//     1
//    / \
//   2   2
//    \   \
//    3    3


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Iteratively  4ms
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        // stack<TreeNode*> stk1;
        // stack<TreeNode*> stk2;
        // stk1.push(root->left);
        // stk2.push(root->right);
        // while(!stk1.empty()&&!stk2.empty()){
        //     TreeNode *n1=stk1.top();
        //     stk1.pop();
        //     TreeNode *n2=stk2.top();
        //     stk2.pop();
        //     if(n1==NULL&&n2==NULL) continue;
        //     if(n1==NULL||n2==NULL) return false;
        //     if(n1->val!=n2->val) return false;
        //     stk1.push(n1->left);
        //     stk2.push(n2->right);
        //     stk1.push(n1->right);
        //     stk2.push(n2->left);
        // }
        // return true;
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        stack<TreeNode*> stk;
        stk.push(root->left);
        stk.push(root->right);
        while(!stk.empty()){
            TreeNode *n1=stk.top();
            stk.pop();
            TreeNode *n2=stk.top();
            stk.pop();
            if(n1==NULL&&n2==NULL) continue;
            if(n1==NULL||n2==NULL) return false;
            if(n1->val!=n2->val) return false;
            stk.push(n1->left);
            stk.push(n2->right);
            stk.push(n1->right);
            stk.push(n2->left);
        }
        return true;
    }
};

// Recursively  8ms
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        return help(root->left, root->right);
    }

    bool help(TreeNode *left, TreeNode *right){
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return help(left->left, right->right) && help(left->right, right->left);
    }
};

//wrong use inorder traversal
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        vector<int> nodes;
        inorder(root,nodes);
        vector<int> temp=nodes;
        reverse(temp.begin(),temp.end());
        return nodes==temp?true:false;
    }
    void inorder(TreeNode* node,vector<int> &nodes){
        if(!node) return;
        inorder(node->left,nodes);
        nodes.push_back(node->val);
        inorder(node->right,nodes);
    }
};