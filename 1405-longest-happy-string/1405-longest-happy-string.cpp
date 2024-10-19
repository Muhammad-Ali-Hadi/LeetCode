class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // if(!a && !b && !c)
        // return "";
        
        // unordered_map<char,int> mp;
        // mp['a']=a;
        // mp['b']=b;
        // mp['c']=c;
        
        // string s;
        // while(mp['a'] || mp['b'] || mp['c'])
        // {
        //     int as=0,bs=0,cs=0;
        //     while(as!=2 && mp['a']>0)
        //     {
        //         s+='a';
        //         as++;
        //         mp['a']++;
        //     }

        //     while(bs!=2 && mp['b']>0)
        //     {
        //         s+='b';
        //         bs++;
        //         mp['b']++;
        //     }

        //     while(cs!=2 && mp['c']>0)
        //     {
        //         s+='c';
        //         cs++;
        //         mp['c']--;
        //     }

        //     if(!a && !b && !c)
        //     break;
        // }
        if(!a && !b && !c)
        return "";

        string s;
        vector<pair<char,int>> freqs;
        freqs.emplace_back('a',a);
        freqs.emplace_back('b',b);
        freqs.emplace_back('c',c);
        
        bool isAdded=false;
        while(!isAdded)
        {
            sort(freqs.begin(),freqs.end(),[](pair<char,int>& a,pair<char,int>& b)
            {
                return a.second>b.second;
            });

            bool isAdded=false;
            for(int i=0;i<freqs.size();++i)
            {
                if(freqs[i].second==0)
                break;

                if(s.size()>=2 && s[s.size()-1]==freqs[i].first && s[s.size()-2]==freqs[i].first)
                continue;

                s+=freqs[i].first;
                freqs[i].second--,isAdded=true;
                break;
            }
            if(!isAdded)
            break;
        }

        return s;
    }
};