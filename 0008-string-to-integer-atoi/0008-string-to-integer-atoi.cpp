class Solution {
public:
    int myAtoi(string s) {
        int sign=1;
        int i=0;
        long long int num=0;

        while(i<s.size() && s[i]==' ')
        {
            ++i;
        }

        if(i<s.size() && (s[i]=='+' || s[i]=='-'))
        {
            sign=(s[i]=='-') ? -1 : 1;
            ++i;
        }

        function<int(int)>helper=[&](int i)->int
        {
            if(i>=s.size() || s[i]<'0' || s[i]>'9')
            return num*sign;

            num=num*10+(s[i]-'0');

            if(sign==1 && num>INT_MAX)
            return INT_MAX;

            if(sign==-1 && -num<INT_MIN)
            return INT_MIN;

            return helper(i+1);
        };

        return helper(i);
    }
};