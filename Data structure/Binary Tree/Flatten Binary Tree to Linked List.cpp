// Flatten Binary Tree to Linked List 
// Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
// The flattened tree should look like:
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if(!root ) return;//|| (root->left==NULL && root->right==NULL)) return;
    if(root->left){
        TreeNode *nl = root->left;
        
        //if(root->right) {
            TreeNode *nr = root->right;
            while(nl->right) 
                nl = nl->right;
            nl->right = nr;
        //}
        root->right = root->left;
        root->left =NULL;  //不能缺
        flatten(root->right);
    }
    else flatten(root->right);
}

//no recursive
void flatten(TreeNode *root) {
    while (root) {
        if (root->left && root->right) {
            TreeNode* t = root->left;
            while (t->right)
                t = t->right;
            t->right = root->right;
        }

        if(root->left)
            root->right = root->left;
        root->left = NULL;
        root = root->right;
    }
}

int main(){
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	TreeNode *t4 = new TreeNode(4);
	TreeNode *t5 = new TreeNode(5);
	TreeNode *t6 = new TreeNode(6);
	TreeNode *t7 = new TreeNode(7);
	TreeNode *t8 = new TreeNode(8);
	TreeNode *t9 = new TreeNode(9);
	TreeNode *t10 = new TreeNode(10);
	t1->left=t2,t1->right=t6;
	t2->left=t3;
	t3->left=t4,t3->right=t5;
	t6->left=t7,t6->right=t8;
	t8->left=t9,t8->right=t10;
	
	
	flatten(t1);
	while(t1){
		cout<<t1->val<<" ";
		t1 = t1->right;
	}
	return 0;
}
