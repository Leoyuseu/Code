// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

// An example is the root-to-leaf path 1->2->3 which represents the number 123.

// Find the total sum of all root-to-leaf numbers.

// For example,

//     1
//    / \
//   2   3
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.

// Return the sum = 12 + 13 = 25.


#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum=0;
        vector<int> path;
        if(!root) return 0;
        fpath(root, path, sum);
        return sum;
    }
    void fpath(TreeNode *node, vector<int> &path, int &sum){
        if(!node) return;
        path.push_back(node -> val);
        if(node->left == NULL && node->right == NULL){
            int num = 0;
            for(auto nodeval : path){
            	cout << nodeval <<" ";
                num = num * 10 + nodeval;
            }
            sum += num;
        }
        if(node -> left)
            fpath(node -> left, path, sum);
        if(node -> right)
            fpath(node -> right, path, sum);
        path.pop_back();
    }
};

class Solution {
public:
   int sumNumbers(TreeNode *root) {
      return  sumNumberUtil(root,0);

   }
   // preorder
   int sumNumberUtil(struct TreeNode* node, int val){
       if(!node) return 0;
       val= val*10+node->val;
       if(node->left==NULL && node->right==NULL)
           return val;
       return sumNumberUtil(node->left,val)+sumNumberUtil(node->right, val);
   }
};

int main(){
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1 -> left = t2;
	t1 -> right = t3;
	Solution st;
	int sum = st.sumNumbers(t1); 
	cout << "sum:" << sum << endl;
	delete t1;
	delete t2;
	delete t3;
	return 0;
}
