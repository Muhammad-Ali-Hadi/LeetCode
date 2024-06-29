class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> nums;
        unordered_map<int,int> mp; 
        for(int i=0;i<nums2.size();++i)
        {
            while(!nums.empty() && nums.top()<nums2[i])
            {
                mp[nums.top()]=nums2[i];
                nums.pop();
            }
            nums.push(nums2[i]);
        }
        while(!nums.empty())
        {
            mp[nums.top()]=-1;
            nums.pop();
        }
        vector<int> result;
        for(int i=0;i<nums1.size();++i)
        {
            result.push_back(mp[nums1[i]]);
        }
        return result;
    }
};