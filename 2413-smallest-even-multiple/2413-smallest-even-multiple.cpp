class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n==2)
        return n;
        int num=0;
        for(int i=2;i<n;i+=2)
        {
            if(n%i==0)
            {
                num=n;
                break;
            }
        }
        return (num==0) ? n*2 : num;
    }
};