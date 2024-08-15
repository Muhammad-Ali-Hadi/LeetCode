class Solution {
public:
    double myPow(double x,long long int n,double pow=1,long long int i=0) {
        if(x==1 || n==0)
        return 1;
        if(x==-1)
        return (n%2==0) ? 1 : -1;

        // if(n>0)
        // {
        //     if(i==n)
        //     return pow;
        //     return myPow(x,n,pow*x,i+1);
        // }
        // if(i==n)
        // return 1/pow;
        // return myPow(x,n,pow*x,i-1);

        if(n<0)
        {
            x=1/x;
            n*=-1;
        }

        if(i==n)
        return pow;
        return myPow(x,n,x*pow,i+1);
    }
};