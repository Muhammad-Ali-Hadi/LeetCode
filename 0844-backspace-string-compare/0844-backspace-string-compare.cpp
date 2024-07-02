class Solution {
public:
    string buildString(string str)
    {
        stack<char> st;
        for(int i=0;i<str.size();++i)
        {
            if(str[i]=='#')
            {
                if(!st.empty())
                st.pop();
            }
            else
            st.push(str[i]);
        }
        string result;
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        return buildString(s)==buildString(t);
    }
};