class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parenthesis;
        function<void(string,int,int)>generate=[&](string s,int open,int close)->void
        {
            if(s.length()==2*n)
            {
                parenthesis.push_back(s);
                return;
            }

            if(open<n)
            {
                generate(s+'(',open+1,close);
            }

            if(close<open)
            {
                generate(s+')',open,close+1);
            }
        };
        generate("",0,0);
        return parenthesis;
    }
};