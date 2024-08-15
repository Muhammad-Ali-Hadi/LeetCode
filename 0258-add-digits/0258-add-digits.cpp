class Solution {
public:
    int addDigits(int num) {
        // if(num>9)
        // {
        //     if(num%9==0)
        //         return 9;
        //         return num%9;
        // }
        // return num;

        // Solution 2 by Recursion
        if(num<10)
        return num;
        return (num%10+addDigits(num/10)>9) ? addDigits(num%10+addDigits(num/10)) : num%10+addDigits(num/10);
    }
};