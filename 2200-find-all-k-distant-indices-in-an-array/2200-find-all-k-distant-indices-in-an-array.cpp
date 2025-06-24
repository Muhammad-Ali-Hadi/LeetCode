#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define forn(x,n) for(int i=x;i<n;++i)
#define fori(x,n) for(int i=x;i<n;++i)
#define forj(y,m) for(int j=y;j<m;++j)

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        speed;
        vector<int> keyIndices;
        forn(0,nums.size())
        {
            if(nums[i]==key)
            keyIndices.push_back(i);
        }

        set<int> res;
        fori(0,keyIndices.size())
        {
            forj(0,nums.size())
            {
                if(abs(keyIndices[i]-j)<=k)
                {
                    res.insert(j);
                }
            }
        }
        return vector<int>(res.begin(),res.end());
    }
};