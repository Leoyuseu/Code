#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> kval;
void inorder(TreeNode* node,int k,vector<int> &kval){
    for(auto v:kval)
    	cout<<v<<" ";
	cout<<endl;
	//if(kval.size()==k) return;
    if(node->left) inorder(node->left,k,kval);
    if(kval.size()==k) return;
    kval.push_back(node->val);
    if(node->right) inorder(node->right,k,kval);
}
int kthSmallest(TreeNode* root, int k) {
    int res=0;
    if(!root) return 0;
    if(!(root->left) && !(root->right)) return root->val;
    inorder(root,k,kval);
    res=kval.back();
    return res;
}

//solution with a stack
int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    while(root || !s.empty())
    {
        if(root)
        {
            s.push(root);
            root=root->left;
        }
        else
        {
            root=s.top();
            s.pop();
            if(--k == 0)
                return root->val;
            root=root->right;
        }
    }
}

int main(){
	TreeNode *n1=new TreeNode(2);
	TreeNode *n2=new TreeNode(3);
	n1->right=n2;
	cout<<kthSmallest(n1,1);
}
