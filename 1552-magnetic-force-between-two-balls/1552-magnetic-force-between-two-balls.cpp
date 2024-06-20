class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        // First Approach (Error)
        // sort(position.begin(),position.end());
        // int min=position[0];
        // int max=position[position.size()-1];
        // if(m==2)
        // return max-min;
        // int count=0;
        // for(int i=0;i<position.size();i+=(m-1))
        // {
        //     ++count;
        // }
        // return count;

        // Second Approach
        sort(position.begin(),position.end());
        int result=0;
        int left=1;
        int right=position[position.size()-1]-position[0];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int count=1;
            int prev=position[0];
            for(int i=1;i<position.size();++i)
            {
                if(position[i]-prev>=mid)
                {
                    ++count;
                    prev=position[i];
                }
            }
            if(count>=m)
            {
                result=mid;
                left=mid+1;
            }
            else
            right=mid-1;
        }
        return result;
    }
};

// class Solution {
// public:
//     int maxDistance(vector<int>& position, int m) {
//         sort(position.begin(), position.end());
//         int left = 1;
//         int right = position[position.size()-1] - position[0];
//         int result = 0;
        
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             int count = 1;
//             int prev = position[0];
            
//             for (int i = 1; i < position.size(); ++i) {
//                 if (position[i] - prev >= mid) {
//                     ++count;
//                     prev = position[i];
//                 }
//             }
            
//             if (count >= m) {
//                 result = mid;
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }
        
//         return result;
//     }
// };