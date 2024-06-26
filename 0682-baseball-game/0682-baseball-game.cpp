class Solution {
public:
    long long int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();++i)
        {
            if(operations[i]=="+")
            {
                int top = st.top();
                st.pop();
                int newTop = top + st.top();
                st.push(top);
                st.push(newTop);
            }
            else if (operations[i]== "D")
            st.push(2 * st.top());
            else if (operations[i] == "C")
            st.pop();
            else
            st.push(stoi(operations[i]));
        }
        long long int sum=0;
        while(!st.empty())
        {
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};