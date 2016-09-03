int count_size(TreeNode* root){
    if (!root) return 0;
    return 1+count_size(root->left)+count_size(root->right);
}

//Count Complete Tree Nodes   
int countNodes(TreeNode* root) {
    if(!root) return 0;
    int hl = 0, hr = 0;
    TreeNode *l = root, *r = root;
    while(l) {
        hl++;
        l = l->left;
    }
    while(r) {
        hr++;
        r = r->right;
    }
    if(hl == hr) return pow(2, hl) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}