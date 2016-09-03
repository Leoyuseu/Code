/*test tree
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
 */

//Recursive solution :
void preorder(TreeNode* root, vector<int>& nodes) {
	if (!root) return;
	nodes.push_back(root->val);    //push²Ù×÷·ÅÔÚµÝ¹éÓï¾äÖÐ¼äÔòÎªÖÐÐò£¬·ÅÔÚÁ½ÌõµÝ¹éÖ®ºóÎªºóÐò
	preorder(root->left, nodes);
	preorder(root->right, nodes);
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> nodes;
	preorder(root, nodes);
	return nodes;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//*******************************************//
//LeetCode 144 Binary Tree Preorder Traversal 

//Iterative solution using stack-- - O(n) time and O(n) space;
//Recursive solution-- - O(n) time and O(n) space(considering the spaces of function call stack);
//Morris traversal-- - O(n) time and O(1) space!!!

//preorderTraversal Iterative solution using stack:   DFS
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> nodes;
	stack<TreeNode*> toVisit;
	TreeNode* curNode = root;
	while (curNode || !toVisit.empty()) {
		if (curNode) {
			nodes.push_back(curNode->val);
			if (curNode->right) toVisit.push(curNode->right);  //ÓÐÓÒ×ÓÊ÷ÏÈÈëÕ»
			curNode = curNode->left;
		}
		else {  //Ò¶½ÚµãµÄÏÂÃæ£¬×ªÏòÕ»ÖÐÔªËØ<ÓÒÐÖµÜ>
			curNode = toVisit.top();
			toVisit.pop();
		}
	}
	return nodes;
}

/*postorderTraversal using stack*/    
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> nodes;
	stack<TreeNode*> toVisit;
	TreeNode* curNode = root;
	TreeNode* lastNode = NULL;   //比较特殊
	while (curNode || !toVisit.empty()) {
		if (curNode) {
			toVisit.push(curNode);
			curNode = curNode->left;
		}
		else {   //情况分类
			TreeNode* topNode = toVisit.top();
			if (topNode->right && lastNode != topNode->right)   //ÎÞ×ó×ÓÊ÷£¬ÓÐÓÒ×ÓÊ÷
				curNode = topNode->right;
			else {  //Ò¶½Úµ
				nodes.push_back(topNode->val);
				lastNode = topNode;
				toVisit.pop();
			}
		}
	}
	return nodes;
}

/*inorderTraversal using stack*/
vector<int> inorderTraversal(TreeNode* root) {
	vector<int> nodes;
	stack<TreeNode*> toVisit;
	TreeNode* curNode = root;
	while (curNode || !toVisit.empty()) {
		if (curNode) {
			toVisit.push(curNode);
			curNode = curNode->left;
		}
		else {  
			curNode = toVisit.top();
			toVisit.pop();
			nodes.push_back(curNode->val);
			curNode = curNode->right;
		}
	}
	return nodes;
}


//Morris preorderTraversal :
vector<int> preorderTraversal(TreeNode* root) {
	TreeNode* curNode = root;
	vector<int> nodes;
	while (curNode) {
		if (curNode->left) {
			TreeNode* predecessor = curNode->left;
			while (predecessor->right && predecessor->right != curNode)
				predecessor = predecessor->right;
			if (!(predecessor->right)) {
				nodes.push_back(curNode->val);
				predecessor->right = curNode;
				curNode = curNode->left;
			}
			else {
				predecessor->right = NULL;
				curNode = curNode->right;
			}
		}
		else {
			nodes.push_back(curNode->val);
			curNode = curNode->right;
		}
	}
	return nodes;
}

//Morris postorderTraversal
class Solution{
public:
	void reverseNodes(TreeNode* start, TreeNode* end) {
		if (start == end) return;
		TreeNode* x = start;
		TreeNode* y = start->right;
		TreeNode* z;
		while (x != end) {
			z = y->right;
			y->right = x;
			x = y;
			y = z;
		}
	}
	void reverseAddNodes(TreeNode* start, TreeNode* end, vector<int>& nodes) {
		reverseNodes(start, end);
		TreeNode* node = end;
		while (true) {
			nodes.push_back(node->val);
			if (node == start) break;
			node = node->right;
		}
		reverseNodes(end, start);
	}
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> nodes;
		TreeNode* dump = new TreeNode(0);
		dump->left = root;
		TreeNode* curNode = dump;
		while (curNode) {
			if (curNode->left) {
				TreeNode* predecessor = curNode->left;
				while (predecessor->right && predecessor->right != curNode)
					predecessor = predecessor->right;
				if (!(predecessor->right)) {
					predecessor->right = curNode;
					curNode = curNode->left;
				}
				else {
					reverseAddNodes(curNode->left, predecessor, nodes);
					predecessor->right = NULL;
					curNode = curNode->right;
				}
			}
			else curNode = curNode->right;
		}
		return nodes;
	}
};

//another solution for postorderTraversal
vector<int> postorderTraversal(TreeNode *root) {
	stack<TreeNode*> nodeStack;
	vector<int> result;
	if (root == NULL)
		return result;
	nodeStack.push(root);
	while (!nodeStack.empty())
	{
		TreeNode* node = nodeStack.top();
		result.push_back(node->val);
		nodeStack.pop();
		if (node->left)
			nodeStack.push(node->left);
		if (node->right)
			nodeStack.push(node->right);
	}
	reverse(result.begin(), result.end());
	return result;
}


//***************************************************//
//LeetCode 	102	Binary Tree Level Order Traversal   BFS
//Level Order Traversal using queue or deque
vector<vector<int>> levelOrder(BinaryTreeNode* root) {
	if (root == NULL) return{};
	vector<vector<int>> result;
	vector<int> level;
	queue<BinaryTreeNode*> que;
	int count = 1;
	que.push(root);
	while (!que.empty()){
		if (que.front()->m_pLeft) que.push(que.front()->m_pLeft);
		if (que.front()->m_pRight) que.push(que.front()->m_pRight);
		level.push_back(que.front()->m_nValue);
		que.pop();
		if (--count == 0){
			result.push_back(level);
			level.clear();
			count = que.size();
		}
	}
	return result;
}
void PrintFromTopToBottom(BinaryTreeNode* pRoot){
	if (pRoot == NULL)
		return;
	std::deque<BinaryTreeNode *> dequeTreeNode;
	dequeTreeNode.push_back(pRoot);
	while (!dequeTreeNode.empty()){
		BinaryTreeNode *pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();
		printf("%d ", pNode->m_nValue);
		if (pNode->m_pLeft)
			dequeTreeNode.push_back(pNode->m_pLeft);
		if (pNode->m_pRight)
			dequeTreeNode.push_back(pNode->m_pRight);
	}
}

//Level Order Traversal recursive solution
class Solution{
public:
	vector<vector<int>> ret;
	void buildVector(TreeNode *root, int depth)
	{
		if (root == NULL) return;
		if (ret.size() == depth)
			ret.push_back(vector<int>());
		ret[depth].push_back(root->val);
		buildVector(root->left, depth + 1); 
		buildVector(root->right, depth + 1);
	}
	vector<vector<int> > levelOrder(TreeNode *root) {
		buildVector(root, 0);
		return ret;
	}
};
                                                   