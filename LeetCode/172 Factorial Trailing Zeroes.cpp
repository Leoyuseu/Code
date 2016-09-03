class Solution {
public:
    int trailingZeroes(int n) {
        //int num=0;
        //while(n>=5){
        //    num+=n/5;
        //    n/=5;
        //}
        //return num;
        return n==0 ? 0 : n/5+trailingZeroes(n/5);
    }
};