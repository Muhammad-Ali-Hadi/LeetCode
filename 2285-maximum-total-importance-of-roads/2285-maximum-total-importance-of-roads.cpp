class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        for(auto& i : roads)
        {
            degree[i[0]]++;
            degree[i[1]]++;
        }
        sort(degree.begin(),degree.end(),greater<int>());
        long long int importance=0;
        for(int i=0;i<n;++i)
        {
            importance+=(long long int)(degree[i])*(n-i);
        }
        return importance;
    }
};