class Solution {
public:
    int minimumRecolors(string blocks, int k,int i=0,int j=0,int count=0) {
        if(j==k)
        return count;

        int newCount=count+(blocks[i]=='W' ? 1 : 0);
        int minRecolors=minimumRecolors(blocks,k,i+1,j+1,newCount);


        if(i+k<blocks.size())
        {
            minRecolors=min(minRecolors,minimumRecolors(blocks,k,i+1,0,0));
        }
        return minRecolors;
    }
};