// 和先序遍历思想差不多
// 112 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \      \
//         7    2      1
// return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    bool status=0;
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL) return false;
        vector<int> path;
        int curr=0;
        Path(root,sum,path,curr);
        return status;
    }
private:
    void Path(TreeNode *node,int sum,vector<int> &path,int &curr){
        curr+=node->val;
        path.push_back(node->val);
        if(curr==sum&&(node->left==NULL&&node->right==NULL)){
            status=true;
            return;
        }
        if(node->left)
            Path(node->left,sum,path,curr);
        if(node->right)
            Path(node->right,sum,path,curr);
            
        curr-=node->val;
        path.pop_back();
    }
};

//3 lines
bool hasPathSum(TreeNode *root, int sum) {
    if (root == NULL) return false;
    if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
    return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
}

// 113 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

// For example:
// Given the below binary tree and sum = 22,
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1
// return
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
class Solution {
public:
    int cursum=0;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        if(!root) return res;
        findpath(root,res,path,cursum,sum);
        return res;
    }
private:
    void findpath(TreeNode *node,vector<vector<int>> &res,vector<int> &path,int &cursum,int sum){
        if(!node) return;
        path.push_back(node->val);
        cursum+=node->val;
        if(cursum==sum&&(node->left==NULL&&node->right==NULL)){
            res.push_back(path);
        }
        if(node->left)
            findpath(node->left,res,path,cursum,sum);
        if(node->right)
            findpath(node->right,res,path,cursum,sum);
        
        cursum-=node->val;
        path.pop_back();
    }
};