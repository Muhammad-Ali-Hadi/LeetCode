class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char> brackets={{'(',')'},{'[',']'},{'{','}'}};
        stack<char> st;
        for(auto& i : s)
        {
            if(brackets.find(i)!=brackets.end())
            {
                st.push(i);
            }
            else
            {
                if(st.empty() || brackets[st.top()]!=i)
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};