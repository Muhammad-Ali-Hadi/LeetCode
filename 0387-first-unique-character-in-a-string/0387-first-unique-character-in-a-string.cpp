class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> mp;
        queue<int> q;
        for(int i=0;i<s.size();++i)
        {
            ++mp[s[i]];
            if(mp[s[i]]==1)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int index=q.front();
            if(mp[s[index]]==1)
            return index;
            q.pop();
        }
        return -1;
    }
};