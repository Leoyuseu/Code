class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> uprow={1};
        for(int i=1;i<=rowIndex+1;++i){
            vector<int> nextrow;
            for(int j=0;j<i;++j){
                if(j==0||j==i-1)
                    nextrow.push_back(1);
                else
                    nextrow.push_back(uprow[j-1]+uprow[j]);
            }
            uprow=nextrow;
        }
        return uprow;
    }
};

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector <int> pascal(1,1);
    for(int i=1;i<=rowIndex;i++){
        pascal.push_back(1);
            for(int k=i-1;k>0;k--){
                pascal[k]=pascal[k]+pascal[k-1];
            }
    }
    return pascal;
    }
}; 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector <int> pascal(1,1);
    for(int i=1;i<=rowIndex;i++){
        pascal.push_back(1);
            for(int k=i-1;k>0;k--){
                pascal[k]=pascal[k]+pascal[k-1];
            }
    }
    return pascal;
    }
}; 
