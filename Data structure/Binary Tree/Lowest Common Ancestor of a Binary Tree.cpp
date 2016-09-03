// Given a binary search tree (BST), find the lowest common ancestor (LCA) of 
// two given nodes in the BST.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
// is defined between two nodes v and w as the lowest node in T that has both v 
// and w as descendants (where we allow a node to be a descendant of itself).”

//         _______6______
//        /              \
//     ___2__          ___8__
//    /      \        /      \
//    0      _4       7       9
//          /  \
//          3   5
// For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. 
// Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant 
// of itself according to the LCA definition.

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Iterative Solutions
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL) return NULL;
    TreeNode *tofind = root;
    if(p->val > q->val){
        TreeNode *temp = p;
        p = q;
        q = temp;
    }
    while(tofind){
        if(p->val < tofind->val && q->val < tofind->val) tofind = tofind->left;
        else if(tofind->val < p->val && tofind->val < q->val) tofind = tofind->right;
        else return tofind;
    }
}

//Recursive Solutions
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p -> val < root -> val && q -> val < root -> val)
        return lowestCommonAncestor(root -> left, p, q);
    if (p -> val > root -> val && q -> val > root -> val)
        return lowestCommonAncestor(root -> right, p, q);
    return root;
}

// ***************Lowest Common Ancestor of a Binary Tree ********************
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes
// in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor 
// is defined between two nodes v and w as the lowest node in T that has both v 
// and w as descendants (where we allow a node to be a descendant of itself).”
//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2       0       8
//          /  \
//          7   4
// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. 
// Another example is LCA of nodes 5 and 4 is 5, since a node can be a 
// descendant of itself according to the LCA definition.
/*研究一下*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};


int main(int argc, char const *argv[])
{
	TreeNode *t1 = new TreeNode(6);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(0);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(3);
	TreeNode *t6 = new TreeNode(5);
	TreeNode *t7 = new TreeNode(8);
	TreeNode *t8 = new TreeNode(7);
	TreeNode *t9 = new TreeNode(9);
	t1->left = t2;
	t1->right = t7;
	t2->left = t3;
	t2->right = t4;
	t4->left = t5;
	t4->right = t6;
	t7->left = t8;
	t7->right = t9;
	TreeNode *tofind = lowestCommonAncestor(t1, t5, t6);
	cout << tofind->val;
	return 0;
}

