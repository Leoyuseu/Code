class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        while(res * res < x){
            ++res;
        }
        return res;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        int res = x / 2;
        while(1){
            if(res * res == x || res * res < x && (res + 1) * (res + 1) > x) return res;
            else if(res * res < x) ++res;
            else res /= 2;
        }
    }
};
//以上都TLE


//binary search
class Solution {
public:
    int mySqrt(int x) {
        int low = 0,  high = x, mid;
        if(x<2) return x; // to avoid mid = 0
        while(low<high) {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return high-1;

    }
};