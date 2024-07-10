class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> folder;
        for(int i=0;i<logs.size();++i)
        {
            if(logs[i]=="../")
            {
                if(!folder.empty())
                folder.pop();
            }
            else if(logs[i]!="./")
            folder.push(logs[i]);
        }
        return folder.size();
    }
};