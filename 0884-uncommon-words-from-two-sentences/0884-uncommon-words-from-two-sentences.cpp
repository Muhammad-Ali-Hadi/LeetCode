class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mp;
        function<void(string)>extractWords=[&](string s)
        {
            for(int i=0,j=0;i<=s.size();++i)
            {
                if(s[i]==' ' || i==s.size())
                {
                    mp[s.substr(j,i-j)]++;
                    j=i+1;
                }
            }
        };

        extractWords(s1);
        extractWords(s2);

        vector<string> uncommons;
        for(auto& word : mp)
        {
            if(word.second==1)
            uncommons.push_back(word.first);
        }
        return uncommons;
    }
};