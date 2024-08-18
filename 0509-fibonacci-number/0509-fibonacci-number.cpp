class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,-1);
        function<int(int)>fib=[&](int num)->int
        {
            if(num==0 || num==1)
            return num;

            if(dp[num]!=-1)
            return dp[num];

            dp[num]=fib(num-1)+fib(num-2);
            return dp[num];
        };
        return fib(n);
    }
};