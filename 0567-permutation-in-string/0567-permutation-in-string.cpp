class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        for(int i=0;i<s2.size();++i)
        {
            for(int j=0;j<s1.size();++j)
            {
                swap(s1[0],s1[1]);
                if(s1==s2.substr(i,s1.size()))
                return true;
            }
        }
        return false;
    }
};