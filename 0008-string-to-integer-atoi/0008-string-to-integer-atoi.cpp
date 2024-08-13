class Solution {
public:
    int myAtoi(string s) {
        int num=0;
        int i=0;
        while(s[i]==' ')
        {
            ++i;
        }

        int sign=1;
        if(s[i]=='+')
        {
            sign=1;
            ++i;
            if(s[i]==48)
            ++i;
        }
        else if(s[i]=='-')
        {
            sign=-1;
            ++i;
            if(s[i]==48)
            ++i;
        }

        int k=i;
        int size=0;
        while(k<s.size())
        {
            if(s[k]>=48 && s[k]<=57)
            {
                if(k==i && s[k]==48)
                {
                    ++k;
                    ++i;
                    continue;
                }
                ++size;
            }
            else
            break;
            ++k;
        }
        try
        {
            if(size>0)
            num=stoi(s.substr(i,size));
        }
        catch(out_of_range&)
        {
            return sign==1 ? INT_MAX : INT_MIN;
        }
        
        return num*sign;
    }
};