int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    else return 1+max(maxDepth(root->left),maxDepth(root->right));
}


int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (!root->left) return 1 + minDepth(root->right);
    else if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}