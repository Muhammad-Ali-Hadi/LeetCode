class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        for(int i=0;i<names.size();++i)
        {
            for(int j=i+1;j<names.size();++j)
            {
                if(heights[i]<heights[j])
                {
                    int temp=heights[i];
                    heights[i]=heights[j];
                    heights[j]=temp;
                    string tem=names[i];
                    names[i]=names[j];
                    names[j]=tem;
                }
            }
        }
        return names;
    }
};

// With Recursion Time Complexity Error on 48th Test Case
// class Solution {
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights,int i=1,int size=0) {
//         if(size==names.size())
//         return names;
//         if(i==names.size())
//         return sortPeople(names,heights,size+1,size+1);
//         if(heights[size]<heights[i])
//         {
//             int temp=heights[size];
//             heights[size]=heights[i];
//             heights[i]=temp;
//             string tem=names[size];
//             names[size]=names[i];
//             names[i]=tem;
//             return sortPeople(names,heights,i+1,size);
//         }
//         return sortPeople(names,heights,i+1,size);
//     }
// };