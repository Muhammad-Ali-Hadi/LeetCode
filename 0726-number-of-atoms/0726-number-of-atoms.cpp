#include<bits/stdc++.h>
class Solution {
public:
    string countOfAtoms(string formula) {
        int i=0;
        stack<unordered_map<string,int>> st;
        st.push(unordered_map<string,int>());
        while(i<formula.size())
        {
            if(formula[i]=='(')
            {
                st.push(unordered_map<string,int>());
                ++i;
            }
            else if(formula[i]==')')
            {
                auto top=st.top();
                st.pop();
                ++i;
                int start=i;
                while(i<formula.size() && isdigit(formula[i]))
                {
                    ++i;
                }
                int multiplier=(start<i) ? stoi(formula.substr(start,i-start)) : 1;
                for(auto& pair : top)
                {
                    st.top()[pair.first]+=pair.second*multiplier;
                }
            }
            else
            {
                int start=i;
                ++i;
                while(i<formula.size() && islower(formula[i]))
                {
                    ++i;
                }
                string element=formula.substr(start,i-start);
                start=i;
                while(i<formula.size() && isdigit(formula[i]))
                {
                    ++i;
                }
                int count=(start<i) ? stoi(formula.substr(start,i-start)) : 1;
                st.top()[element]+=count;
            }
        }
        map<string,int> sorted(st.top().begin(),st.top().end());
        string result;
        for(auto& pair : sorted)
        {
            result+=pair.first;
            if(pair.second>1)
            {
                result+=to_string(pair.second);
            }
        }
        return result;
    }
};