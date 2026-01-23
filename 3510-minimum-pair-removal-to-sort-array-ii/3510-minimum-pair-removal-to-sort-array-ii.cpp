#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define speed ios_base::sync_with_stdio(false),cin.tie(nullptr)
#define forn(x,n) for(int i=x;i<n;++i)
#define fori(x,n) for(int i=x;i<n;++i)
#define forj(y,m) for(int j=y;j<m;++j)
#define forR(x,n) for(int i=x;i>=n;--i)
#define ll long long int
#define veci vector<int>
#define vecll vector<ll>
#define vecpll vector<pair<ll,ll>> 
#define nl cout<<"\n" 

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        speed;

        vecll arr(nums.begin(),nums.end());
        ordered_set<pair<ll,ll>> set;
        vecpll list(nums.size()); // {prev,next}
        fori(0,nums.size())
        {
            list[i].first=i-1;
            list[i].second=i+1;
        }

        int count=0;
        forn(0,nums.size()-1)
        {
            if(arr[i]>arr[i+1])
            ++count;
            set.insert({arr[i]+arr[i+1],i});
        }

        int op=0;
        while(count)
        {
            int i=set.begin()->second;
            int j=list[i].second;
            int k=list[i].first;
            int l=list[j].second;

            if(arr[i]>arr[j])
            --count;
            if(k>=0)
            {
                if(arr[k]>arr[i] && arr[k]<=arr[i]+arr[j])
                --count;
                else if(arr[k]<=arr[i] && arr[k]>arr[i]+arr[j])
                ++count;
            }
            if(l<nums.size())
            {
                if(arr[l]>arr[j] && arr[l]<arr[i]+arr[j])
                ++count;
                else if(arr[l]<arr[j] && arr[l]>=arr[i]+arr[j])
                --count;
            }

            set.erase(set.begin());
            if(k>=0)
            {
                if(set.find({arr[i]+arr[i],k})!=set.end())
                set.erase({arr[k]+arr[i],k});
                set.insert({arr[k]+arr[i]+arr[j],k});
            }
            if(l<nums.size())
            {
                if(set.find({arr[j]+arr[l],j})!=set.end())
                set.erase({arr[j]+arr[l],j});
                set.insert({arr[i]+arr[j]+arr[l],i});
                list[l].first=i;
            }
            list[i].second=l;
            arr[i]+=arr[j];
            ++op;
        }
        return op;
    }
};