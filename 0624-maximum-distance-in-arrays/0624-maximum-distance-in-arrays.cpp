class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays,int i=1,int maxVal=0,int minVal=0) {
        if(i==arrays.size())
        {
            return maxVal-minVal;
        }

        if(i==1)
        {
            maxVal=arrays[0].back();
            minVal=arrays[0][0];
        }
        // max=(arrays[i].back()>max) ? arrays[i].back() : max;
        // min=(arrays[i][0]<min) ? arrays[i][0] : min; 
        maxVal=max(maxVal,arrays[i].back());
        minVal=min(minVal,arrays[i][0]);
        return maxDistance(arrays,i+1,maxVal,minVal);
    }
};