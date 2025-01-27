class Solution{
    public:
bool isPerfectSquare(int num,long long left=0,long long right=-1) {
        if(num==1 || num==0)
        return true;

        if(right==-1)
        right=num/2;

        if(left>right)
        return false;

        long long mid=left+(right-left)/2;
        if(mid*mid==num)
        return true;

        if(mid*mid>num)
        return isPerfectSquare(num,left,mid-1);
        else
        return isPerfectSquare(num,mid+1,right);
    }
};