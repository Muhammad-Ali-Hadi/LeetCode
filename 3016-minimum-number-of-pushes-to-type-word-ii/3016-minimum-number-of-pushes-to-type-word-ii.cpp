class Solution {
public:
    int minimumPushes(string word) {
        int pushes=0;
        vector<int> freq(26,0);
        for(int i=0;i<word.size();++i)
        {
            freq[word[i]-'a']++;
        }

        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0,j=8,x=1;i<26;++i,--j)
        {
            if(!j)
            {
                ++x;
                j=8;
            }
            pushes+=freq[i]*x;
        }
        return pushes;
    }
};