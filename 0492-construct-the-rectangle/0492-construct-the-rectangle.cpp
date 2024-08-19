class Solution {
public:
    vector<int> constructRectangle(int area,int W=0,int L=0) {
        function<vector<int>(int)>helper=[&](int W)->vector<int>
        {
            if(area%W==0)
            return {area/W,W};

            return helper(W-1);
        };
        return helper(sqrt(area));
    }
};