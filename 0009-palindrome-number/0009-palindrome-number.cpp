class Solution {
public:
    bool helper(string s,int n=0)
    {
        if(n==s.size()/2)
        return true;
        if(s[n]!=s[s.size()-n-1])
        {
            return false;
        }
        return helper(s,n+1);
    }

    bool isPalindrome(int x) {
        // string str=to_string(x);
        
        // int left=0;
        // int right=str.size() - 1;
        
        // while(left<right) 
        // {
        //     if(str[left]!=str[right]) 
        //     { 
        //         return false; 
        //     }
        //     left++;
        //     right--;
        // }
        // return true;

        // Solution with Indirect Recursion
        if(x<0)
        return false;
        string str=to_string(x);
        return helper(str);
    }
};