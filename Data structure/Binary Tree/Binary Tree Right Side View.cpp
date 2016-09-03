// Binary Tree Right Side View 
// Given a binary tree, imagine yourself standing on the right side of it, 
// return the values of the nodes you can see ordered from top to bottom.

// For example:
// Given the following binary tree,
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
// You should return [1, 3, 4].

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        sideview(root, ans, 0);
        return ans;
    }
    void sideview(TreeNode *node, vector<int> &ans, int i) {
        if(!node) return;
        if(i == ans.size()){    //ans,size()代表着层数
            ans.push_back(node->val);
        }
        sideview(node->right, ans, i + 1);
        sideview(node->left, ans, i + 1);
    }
};