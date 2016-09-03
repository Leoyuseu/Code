// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

// For example,
// Given n = 3, there are a total of 5 unique BST's.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3

// 令h(0)=1,h(1)=1，catalan数满足递推式[1] ：
// h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (n>=2)
// 例如：h(2)=h(0)*h(1)+h(1)*h(0)=1*1+1*1=2
// h(3)=h(0)*h(2)+h(1)*h(1)+h(2)*h(0)=1*2+1*1+2*1=5
// 另类递推式：
// h(n)=h(n-1)*(4*n-2)/(n+1);
// 递推关系的解为：
// h(n)=C(2n,n)/(n+1) (n=0,1,2,...)
// 递推关系的另类解为：
// h(n)=c(2n,n)-c(2n,n-1)(n=0,1,2,...)

// (1)一个栈(无穷大)的进栈序列为1，2，3，…，n，有多少个不同的出栈序列?  

// (2)在一个凸多边形中，通过若干条互不相交的对角线，把这个多边形划分成了若干个三角形。
//    任务是键盘上输入凸多边形的边数n，求不同划分的方案数f（n）比如当n=6时，f（6）=14。

// (3)给定N个节点，能构成多少种不同的二叉搜索树？

class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 0;
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        for(int i = 1; i <= n; i++){
            int num = 0;
            for(int k = 1; k <= i; k++){
                num += nums[k - 1] * nums[i - k];
            }
            nums[i] = num;
        }
        return nums.back();
    }
};

class Solution {
public:
    int numTrees(int n) {
        if(n<2) return n;
        long long numscur=2;
        for(int i=2;i<n;++i){
            numscur=numscur*(4*(i+1)-2)/(i+2);
        }
        return numscur;

        //one line solution
        //return n==1?1:((int)(((long long)numTrees(n-1))*(4*n-2)/(n+1)));
    }
};

int numTrees(int n) {
    int dp[n+1];
    dp[0] = dp[1] = 1;
    for (int i=2; i<=n; i++) {
        dp[i] = 0;
        for (int j=1; j<=i; j++) {
            dp[i] += dp[j-1] * dp[i-j];
        }
    }
    return dp[n];
}



// Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

// For example,
// Given n = 3, your program should return all 5 unique BST's shown below.

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
// 存储结果
vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ret;
    vector<vector<vector<TreeNode*>>> dp(n,vector<vector<TreeNode*>>(n));
    helper(1,n,ret,dp);
    return ret;
}
void helper(int start, int end, vector<TreeNode*> &ret,vector<vector<vector<TreeNode*>>> &dp) {
    if (start > end) {
        ret.push_back(NULL); return;
    }
    if (!dp[start-1][end-1].empty())  {
        ret = dp[start-1][end-1]; return;
    }
    for (int i = start; i <= end; ++i) {
        vector<TreeNode*> left, right;
        helper(start, i-1,left,dp);
        helper(i+1,end,right,dp);
        for(int j = 0; j < left.size(); ++j) {
            for (int k = 0; k < right.size(); ++k) {
                TreeNode* node = new TreeNode(i);
                node->left = left[j];
                node->right = right[k];
                ret.push_back(node);
            }
        }
    }
    dp[start-1][end-1] = ret;
}