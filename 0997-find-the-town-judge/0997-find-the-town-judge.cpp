class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n==1)
        return 1;

        if(trust.size()==1)
        return trust[0][1];

        unordered_map<int,int> trustCount;
        unordered_map<int,int> trustedBy;
        for(int i=0;i<trust.size();++i)
        {
            trustCount[trust[i][0]]++;
            trustedBy[trust[i][1]]++;
        }

        for(int i=0;i<trust.size();++i)
        {
            if(!trustCount[trust[i][1]] && trustedBy[trust[i][1]]==n-1)
            return trust[i][1];
        }

        return -1;
    }
};