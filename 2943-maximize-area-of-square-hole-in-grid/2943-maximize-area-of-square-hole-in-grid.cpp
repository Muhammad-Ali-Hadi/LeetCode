#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        speed;

        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        auto f=[](vector<int> bars)->int{
            int res=2,streak=2;
            for(int i=1;i<bars.size();++i)
            {
                streak=(bars[i]-bars[i-1]==1) ? ++streak : 2;

                res=max(res,streak);
            }
            return res;
        };
        int ans=min(f(hBars),f(vBars));
        return ans*ans;
    }
};