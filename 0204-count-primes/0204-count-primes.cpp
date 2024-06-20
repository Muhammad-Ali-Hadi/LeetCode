class Solution {
public:
    int countPrimes(int n) {
        // if (n <= 2)
        //     return 0;
        
        // int nNew = (n - 1) / 2;
        // bool *marked = new bool[nNew + 1];
        // memset(marked, false, sizeof(bool) * (nNew + 1));

        // for (int i = 1; i <= nNew; ++i) 
        // {
        //     for (int j = i; (i + j + 2 * i * j) <= nNew; ++j) 
        //     {
        //         marked[i + j + 2 * i * j] = true;
        //     }
        // }

        // int count = 0;
        // for (int i = 1; i <= nNew; ++i) 
        // {
        //     if (!marked[i])
        //         count++;
        // }

        // delete[] marked;

        // My Approach
        // return count + 1;
        // if(n<=2)
        // return 0;
        // if(n==3)
        // return 1;
        // long long int count=2;
        // for(long long int i=n-1;i>=5;--i)
        // {
        //     bool flag=true;
        //     for(long long int j=2;j<i;++j)
        //     {
        //         if(i%j==0)
        //         {
        //             flag=false;
        //             break;
        //         }
        //     }
        //     if(flag)
        //     ++count;
        // }
        // return count;

        if(n<=2)
        return 0;
        // Sieve of Eratosthene
        vector<bool> isPrime(n,true);
        isPrime[0]=isPrime[1]=false;
        for(int i=2;i*i<n;++i)
        {
            if(isPrime[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    isPrime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;++i)
        {
            if(isPrime[i])
            ++count;
        }
        return count;
    }
};