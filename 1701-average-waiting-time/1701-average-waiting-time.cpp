class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long int sum=0;
        long long int time=0;
        for(int i=0;i<customers.size();++i)
        {
            long long int arrivalTime=customers[i][0];
            long long int cookingTime=customers[i][1];
            time=max(time,arrivalTime)+cookingTime;
            sum+=time-arrivalTime;
        }
        return (double)sum/customers.size();
    }
};