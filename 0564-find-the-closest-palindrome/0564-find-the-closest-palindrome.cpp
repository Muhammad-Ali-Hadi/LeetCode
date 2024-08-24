class Solution {
public:
    string nearestPalindromic(string n) {
        if(stol(n)<10)
        return to_string(stol(n)-1);

        int length=n.size();
        vector<long long> candidates;
        candidates.push_back((long long)pow(10,length-1)-1);
        candidates.push_back((long long)pow(10,length)+1);

        long long prefix=stol(n.substr(0,(length+1)/2));
        for(int i=-1;i<=1;++i)
        {
            string candidate=to_string(prefix+i);
            string palindrome=candidate+string(candidate.rbegin()+(length%2),candidate.rend());
            candidates.push_back(stol(palindrome));
        }

        long long num=stol(n);
        long long minDiff=INT_MAX;
        long long nearPalindrome;
        for(long long candidate : candidates)
        {
            if(candidate!=num)
            {
                long long diff=abs(candidate-num);
                if(diff<minDiff || (diff==minDiff && candidate<nearPalindrome))
                {
                    minDiff=diff;
                    nearPalindrome=candidate;
                }
            }
        }
        return to_string(nearPalindrome);
    }
};