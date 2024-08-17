class Solution {
public:
    int countWhites(string blocks,int k,int start)
    {
        if(k==0)
        return 0;

        return (blocks[start]=='W')+countWhites(blocks,k-1,start+1);
    }

    int minimumRecolors(string blocks, int k) {
        int minRecolors=10e7;

        function<void(int)>slideWindow=[&](int start)
        {
            if(start+k>blocks.size())
            return;

            int recolors=countWhites(blocks,k,start);
            minRecolors=min(minRecolors,recolors);

            slideWindow(start+1);
        };

        slideWindow(0);
        return minRecolors;
    }
};