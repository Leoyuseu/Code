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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums, int first, int last){
        if(first > last) return NULL;
        int mid = (first + last) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, first, mid-1);
        root->right = sortedArrayToBST(nums, mid + 1, last);
        return root;
    }
};