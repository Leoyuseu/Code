// Balanced Binary Tree 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ifBalanced_helper(TreeNode* root, bool& result){
        if(!root) return 0;
        int leftHeight = ifBalanced_helper(root->left, result);
        int rightHeight = ifBalanced_helper(root->right, result);
        if(abs(leftHeight-rightHeight)>1) result = false;
        return max(leftHeight, rightHeight)+1;
    }

    bool isBalanced(TreeNode *root) {
        bool result = true;
        ifBalanced_helper(root, result);
        return result;
    }
};


//*****************Validate Binary Search Tree ****************************
// Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
        vector<int> nodes;
        inorder(root,nodes);
        auto it=unique(nodes.begin(),nodes.end());
        if(it!=nodes.end()) return false;
        return is_sorted(nodes.begin(),nodes.end());
    }
    void inorder(TreeNode* node,vector<int> &nodes){
        if(!node) return;
        inorder(node->left,nodes);
        nodes.push_back(node->val);
        inorder(node->right,nodes);
    }
};