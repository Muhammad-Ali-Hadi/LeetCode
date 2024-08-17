class Solution {
public:
    int MOD=1e9+7;
    long long power(long long b,long long e,long long ans)
    {
        if(e==0)
        return ans;
        if(e%2!=0)
        return power(b,e-1,(ans*b)%MOD);
        return power((b*b)%MOD,e/2,ans);
    }

    int countGoodNumbers(long long n,long long i=0) {
        long long temp=power(20,n/2,1);
        return (n%2!=0) ? (temp*5)%MOD : temp;
    }
};