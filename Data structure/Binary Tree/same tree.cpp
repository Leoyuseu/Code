bool isSameTree(TreeNode* p, TreeNode* q){
        return !p && !q ? true : (p && q && p->val == q->val ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false);
}

//clear solution
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if(p==NULL||q==NULL){
            if(p==NULL&&q==NULL)
                return 1;
            else
                return 0;
        }
        if(p->val!=q->val)
            return 0; 
        else
            return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};