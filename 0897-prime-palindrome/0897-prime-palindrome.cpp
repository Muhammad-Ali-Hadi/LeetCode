class Solution {
public:

    bool isPalindrome(int n){
        string str = to_string(n);
        
        for(int i = 0;i < str.size(); i++){
            
            if(str[i] != str[str.size()-i-1]){
                return false;
            }
        }
        return true;
    }

    bool isPrime(int n){
        if(n==2 || n == 3)  return true;
        if(n <= 1 || n % 2 == 0 || n % 3 == 0)  return false;
        
        for(int i = 5;i*i<= n; i+=6){
            if(n % i == 0 || n % (i+2) == 0)
                return false;
        }
        return true;
    }

    int primePalindrome(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        n = n==1 ? 2 : n;
        // 1e3 == 1x 10 pow 3
        while(1){
            if((n > 1e3 && n < 1e4) ||
               (n > 1e5 && n < 1e6) ||
               (n > 1e7 && n < 1e8)){

                n = pow(10, ceil(log10(n)));
                continue;
               }

               if(isPalindrome(n) && isPrime(n)){
                    return n;
               }
               n++;
        }
        return -1;
    }
};