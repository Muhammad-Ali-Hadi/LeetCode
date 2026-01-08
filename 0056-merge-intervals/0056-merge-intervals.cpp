#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        fast;

        sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int> &b){
            return a[0]<b[0];
        });
        vector<vector<int>> ans;
        vector<int> prev=intervals[0];
        for(int i=1;i<intervals.size();++i)
        {
            if(intervals[i][0]<=prev[1])
            prev[1]=max(prev[1],intervals[i][1]);
            else
            {
                ans.push_back(prev);
                prev=intervals[i];
            }
        }
        ans.push_back(prev);
        return ans;
    }
};