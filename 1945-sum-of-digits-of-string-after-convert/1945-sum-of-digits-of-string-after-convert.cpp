class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for(int i=0;i<s.size();++i)
        {
            str+=to_string(s[i]-96);
        }
        
        while(k--!=0)
        {
            int sum=0;
            for(int i=0;i<str.size();++i)
            {
                sum+=str[i]-'0';
            }
            str=to_string(sum);
        }
        return stoi(str);
    }
};