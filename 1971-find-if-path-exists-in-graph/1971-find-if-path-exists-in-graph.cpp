class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1 || edges.empty())
        return true;

        for(int i=0;i<edges.size();++i)
        {
            if((edges[i][0]==source && edges[i][1]==destination) || (edges[i][0]==destination && edges[i][1]==source))
            return true;
        }
        return false;
    }
};