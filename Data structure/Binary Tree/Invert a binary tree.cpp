// Invert a binary tree.

//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// to
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//**********recursive solution.
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        swapChild(root);
        return root;
    }
    void swapChild(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left!=NULL)
            swapChild(root->left);
        if(root->right!=NULL)
            swapChild(root->right);
        TreeNode *temp=root->right;
        root->right=root->left;
        root->left=temp;
        //swap(root->left,root->right);
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL||(root->left==NULL&&root->right==NULL))
            return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

//iterative solution --level-order traversal
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()) {
            TreeNode* node = level.front();
            level.pop();
            swap(node -> left, node -> right);
            if (node -> left) level.push(node -> left);
            if (node -> right) level.push(node -> right);
        }
        return root; 
    }

    TreeNode* invertTree(TreeNode* root) {
        std::stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            if (p) {
                stk.push(p->left);
                stk.push(p->right);
                std::swap(p->left, p->right);
            }
        }
        return root;
    }
};

