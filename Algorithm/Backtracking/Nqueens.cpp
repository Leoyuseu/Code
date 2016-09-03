// The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
// such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle.

// Each solution contains a distinct board configuration of the n-queens' 
// placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

// For example,
// There exist two distinct solutions to the 4-queens puzzle:

// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],

//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]


//nice solution backtracking
class Solution { 
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string> > queens;
        vector<int> colPos(n, 0);
        solve(colPos, n, 0, queens);
        return queens;
    }
private:
    bool noAttack(vector<int>& colPos, int row, int col) {  //不互相攻击条件
        for (int r = row - 1, ld = col - 1, rd = col + 1; r >= 0; r--, ld--, rd++)
            if (colPos[r] == col || colPos[r] == ld || colPos[r] == rd)
                return false;
        return true;
    }
    vector<string> queenStr(vector<int>& colPos) {
        int n = colPos.size();
        vector<string> queen(n, string(n, '.'));
        for (int i = 0; i < n; i++)
            queen[i][colPos[i]] = 'Q';
        return queen;
    }
    void solve(vector<int>& colPos, int n, int row, vector<vector<string> >& queens) {
        if (row == n) {    //终止条件
            queens.push_back(queenStr(colPos));
            return;
        }
        for (int col = 0; col < n; col++) {
            colPos[row] = col;
            if (noAttack(colPos, row, col))
                solve(colPos, n, row + 1, queens);
        }
    }
};


//借鉴上面的解决加上自己的
class Solution {
public:
    bool noAttack(vector<int>& colPos, int row, int col) {  //不互相攻击条件
        for (int r = row - 1, ld = col - 1, rd = col + 1; r >= 0; r--, ld--, rd++)
            if (colPos[r] == col || colPos[r] == ld || colPos[r] == rd)
                return false;
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> fit(n, 0);
        if(n < 1) return ans;
        solveNQueens(n, 0, ans, fit);
        return ans;
    }
    void solveNQueens(int n, int index, vector<vector<string>> &ans, vector<int> &fit){
        if(index == n ){
            vector<string> temp(n, string(n, '.'));
            for(int i = 0; i < n; ++i)
                temp[i][fit[i]] = 'Q';
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n ; ++i){
            fit[index] = i;
            if(noAttack(fit, index, i)){
                solveNQueens(n, index + 1, ans, fit);    
            }
        }
    }
};

//wrong answer
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> fit(n, 0);
        if(n < 1) return ans;
        solveNQueens(n, 0, ans, fit);
        return ans;
    }
    void solveNQueens(int n, int index, vector<vector<string>> &ans, vector<int> &fit){
        if(index = n -1 ){
            vector<string> temp({});
            string pos = "";
            for(int i = 0; i < n; ++i){
                for(int j = 0; i < fit[i]; ++j){
                    pos.push_back('.');
                }
                pos.push_back('Q');
                while(pos.size() != n){
                    pos.push_back('.');
                }
                temp.push_back(pos);
            }
            ans.push_back(temp);
            return;
        }
        for(int i = 0; i < n ; ++i){
            int k = 0;
            fit[index] = i;
            while(k < index){
                if((fit[k] - fit[index])*(abs(fit[k] - fit[index])) - abs(k-index) != 0){
                    k++;
                    if(k == i){
                        solveNQueens(n, index + 1, ans, fit);
                    }
                    else break;
                }
            }
        }
    }
};