class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size()-1;++i)
        {
            if(arr[i]%2==1 && arr[i+1]%2==1)
            ++count;
            else
            count=0;
            if(count==2)
            return true;
        }
        return false;
    }
};