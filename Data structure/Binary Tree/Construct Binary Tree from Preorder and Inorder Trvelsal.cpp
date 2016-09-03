// Construct Binary Tree from Preorder and Inorder Traversal

#include<iostream>
#include<vector>
#include<algorithm> 
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};


//my solution MLE
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.empty()) return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);
    vector<int> in1(inorder.begin(), it);   //不需要存储in1,in2,pre1,pre2
    vector<int> in2(it + 1, inorder.end());
    int n1 = in1.size(), n2 = in2.size();
    vector<int> pre1(preorder.begin()+1, preorder.begin()+1+n1);
    vector<int> pre2(preorder.begin()+1+n1,preorder.end());
    root->left=buildTree(pre1,in1);
    root->right=buildTree(pre2,in2);
    return root;
}

//
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return create(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* create(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps > pe){
            return nullptr;
        }
        TreeNode* node = new TreeNode(preorder[ps]);
        int pos;
        for(int i = is; i <= ie; i++){
            if(inorder[i] == node->val){
                pos = i;
                break;
            }
        }
        node->left = create(preorder, inorder, ps + 1, ps + pos - is, is, pos - 1);
        node->right = create(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
        return node;
    }
};

int main(){
	vector<int> preorder = {1,2,4,5,3,6,7};
	vector<int> inorder = {4,2,5,1,6,7,3};
	TreeNode *root = buildTree(preorder, inorder);
	while(root){
		cout<<"node:"<<root->val<<" left:"<<root->left->val<<" right:"<<root->right->val<<endl;
		root = root->left;
	}
}
