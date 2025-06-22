#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define forn(x,n) for(int i=x;i<n;++i)
#define forj(y,m) for(int j=y;j<m;++j)

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        speed;

        vector<string> res;
        forn(0,s.size())
        {
            string t;
            for(int j=0;j<k;++j)
            {
                if(i+j<s.size())
                t+=s[i+j];
                else
                t+=fill;
            }
            res.push_back(t);
            i+=(k-1);
        }
        return res;
    }
};