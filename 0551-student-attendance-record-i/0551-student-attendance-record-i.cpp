class Solution {
public:
    bool checkRecord(string s,int absCount=0,int lateCount=0,int i=0) {
        if(i==s.size())
        return true;

        if(s[i]=='L' && s[i+1]=='L' && s[i+2]=='L' && i<=s.size()-3)
        lateCount+=3;
        else
        lateCount=0;

        if(s[i]=='A')
        ++absCount;

        if(absCount>=2 || lateCount>=3)
        return false;

        return checkRecord(s,absCount,lateCount,i+1);
    }
};