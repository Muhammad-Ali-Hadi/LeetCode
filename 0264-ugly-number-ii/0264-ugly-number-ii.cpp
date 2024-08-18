class Solution {
public:
    bool isUgly(int n)
    {
        if(n<=0)
        return false;
        while(n%2==0)
        {
            n/=2;
        }
        while(n%3==0)
        {
            n/=3;
        }
        while(n%5==0)
        {
            n/=5;
        }
        return n==1;
    }

    int nthUglyNumber(int n) {
        int count=0;
        int current=1;
        while(count<n)
        {
            if(isUgly(current))
            {
                ++count;
            }
            ++current;
        }
        return current-1;
    }
};