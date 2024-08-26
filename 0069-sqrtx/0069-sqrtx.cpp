class Solution {
public:
    int mySqrt(int x,int num=1) {
        return (num*num>x) ? num-1 : mySqrt(x,num+1);
    }
};