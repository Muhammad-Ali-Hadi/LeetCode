class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        for(int i=0,j=0;i<=s1.size();++i)
        {
            if(s1[i]==' ' || i==s1.size())
            {
                mp[s1.substr(j,i-j)]++;
                j=i+1;
            }
        }

        for(int i=0,j=0;i<=s2.size();++i)
        {
            if(s2[i]==' ' || i==s2.size())
            {
                mp[s2.substr(j,i-j)]++;
                j=i+1;
            }
        }

        vector<string> uncommons;
        for(auto& word : mp)
        {
            if(word.second==1)
            uncommons.push_back(word.first);
        }
        return uncommons;
    }
};