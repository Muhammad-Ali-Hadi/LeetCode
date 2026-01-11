#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        fast;
        if(!matrix.size())
        return 0;

        function<int(vector<int>&)>f=[&](vector<int>& heights)->int{
            stack<int> st;
            heights.push_back(0);
            int maxArea=0;

            for(int i=0;i<heights.size();++i)
            {
                while(!st.empty() && heights[st.top()]>heights[i])
                {
                    int height=heights[st.top()];
                    st.pop();

                    int width=st.empty() ? i : i-st.top()-1;
                    maxArea=max(maxArea,height*width);
                }
                st.push(i);
            }
            heights.pop_back();
            return maxArea;
        };

        int n=matrix.size(),m=matrix[0].size();
        vector<int> heights(m,0);
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(matrix[i][j]==49)
                heights[j]++;
                else
                heights[j]=0;
            }
            ans=max(ans,f(heights));
        }
        return ans;
    }
};