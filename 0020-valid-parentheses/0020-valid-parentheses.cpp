class Solution {
public:
    bool isValid(string s) 
    {
        // unordered_map<char,char> brackets={{'(',')'},{'[',']'},{'{','}'}};
        // stack<char> st;
        // for(auto& i : s)
        // {
        //     if(brackets.find(i)!=brackets.end())
        //     {
        //         st.push(i);
        //     }
        //     else
        //     {
        //         if(st.empty() || brackets[st.top()]!=i)
        //         {
        //             return false;
        //         }
        //         st.pop();
        //     }
        // }
        // return st.empty();
        if(s.size()%2!=0)
        return false;

        stack<char> st;

        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                st.push(s[i]);
            }
            else
            {
                if(st.empty)
                return false;
                
                if((st.top()!='{' && s[i]=='}') || (st.top()!='[' && s[i]==']') || (st.top()!='(' && s[i]==')'))
                return false;
                st.pop();
            }
        }
        return st.empty();
    }
};