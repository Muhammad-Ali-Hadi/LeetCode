class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        for(int i=0;i<customers.size();++i)
        {
            if(customers[i]>=minutes)
            sum+=customers[i];
        }
        int grump=0;
        for(int i=0;i<grumpy.size();++i)
        {
            grump+=grumpy[i];
        }
        return (grump==minutes) ? sum : grump+sum;
    }
};