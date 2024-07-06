class Solution {
public:
    int passThePillow(int n, int time,int k=1,bool flag=true) {
        if(time==0)
        return k;
        if(flag)
        {
            return (k<n) ? passThePillow(n,time-1,k+1,true) : passThePillow(n,time-1,k-1,false);
        }
        else
        {
            return (k>1) ? passThePillow(n,time-1,k-1,false) : passThePillow(n,time-1,k+1,true);
        }
    }
};