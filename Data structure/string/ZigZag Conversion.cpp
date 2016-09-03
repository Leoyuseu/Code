// The string "PAYPALISHIRING" is written in a zigzag pattern on a given 
// number of rows like this: (you may want to display this pattern in a 
// fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given 
// a number of rows:

// string convert(string text, int nRows);
// convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        if(numRows == 1 || s.size() < numRows) return s;
        int rowIndex = 0;
        for(int i = 0; i < numRows; ++i){
            ans += s[i];  //每行第一个
            rowIndex = i + numRows*2 - 2;
            while(rowIndex - 2*i < s.size()){
                if (i != 0 && i != numRows - 1)
                    ans += s[rowIndex - 2 * i];
                if (rowIndex < s.size())
                    ans += s[rowIndex];
                rowIndex += 2*numRows - 2;
            }
        }
        return ans;
    }
};