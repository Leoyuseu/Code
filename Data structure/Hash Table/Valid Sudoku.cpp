// Valid Sudoku
// The Sudoku board could be partially filled, 
// where empty cells are filled with the character '.'.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            unordered_map<char, int> counts1;
            unordered_map<char, int> counts2;
            for(int j = 0; j < 9; ++j){
                if(isdigit(board[i][j])){
                    if(++counts1[board[i][j]] > 1)
                        return false;
                }
                if(isdigit(board[j][i])){
                    if(++counts2[board[j][i]] > 1)
                        return false;
                }
            }
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                unordered_map<char, int> counts3;
                for(int row = 3 * i; row < 3 * i + 3; ++row){
                    for(int column  = 3 * j; column < 3 * j + 3; ++column){
                        if(isdigit(board[row][column])){
                            if(++counts3[board[row][column]] > 1)
                            return false;
                        }
                    }
                    
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            vector<char> row(9, '.');
            for(int j = 0; j < 9; ++j){
                row[j] = board[i][j];
            }
            if(!isValid(row)) return false;
        }
        for(int i = 0; i < 9; ++i){
            vector<char> column(9, '.');
            for(int j = 0; j < 9; ++j){
                column[j] = board[j][i];
            }
            if(!isValid(column)) return false;
        }
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                vector<char> block;
                for(int row = 3 * i; row < 3 * i + 3; ++row){
                    for(int column  = 3 * j; column < 3 * j + 3; ++column){
                        block.push_back(board[row][column]);
                    }
                }
                if(!isValid(block)) return false;
            }
        }
        return true;
    }
    bool isValid(vector<char> nums){
        // nums.erase(remove(nums.begin(), nums.end(), '.'), nums.end());
        // sort(nums.begin(), nums.end());
        // if(unique(nums.begin(), nums.end()) != nums.end()) return false;
        // else return true;
        for(vector<char>::iterator it = nums.begin(); it != nums.end(); ++it){
            if(isdigit(*it)){
                if(find(nums.begin(), nums.end(), *it) != it && 
                   find(nums.begin(), nums.end(), *it) != nums.end())
                   return false;
            }
        }
        return true;
    }
};

//consice solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int used1[9][9] = {0}, used2[9][9] = {0}, used3[9][9] = {0};

        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(used1[i][num] || used2[j][num] || used3[k][num])
                        return false;
                    used1[i][num] = used2[j][num] = used3[k][num] = 1;
                }

        return true;
    }
};