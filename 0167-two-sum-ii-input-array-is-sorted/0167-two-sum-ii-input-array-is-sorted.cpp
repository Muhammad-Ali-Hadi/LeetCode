class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Passing all test cases but giving time complexity error 
        // for(int i=0;i<numbers.size();++i)
        // {
        //     for(int j=i+1;j<numbers.size();++j)
        //     {
        //         if(numbers[i]+numbers[j]==target)
        //         return {i+1,j+1};
        //     }
        // }
        // return {-1,-1};

        int left =0;
        int right=numbers.size()-1;
        while(right>left)
        {
            if(numbers[left]+numbers[right]==target)
            return {left+1,right+1};
            else if(numbers[left]+numbers[right]>target)
            --right;
            else
            ++left;
        }
        return {-1,-1};
    }
};