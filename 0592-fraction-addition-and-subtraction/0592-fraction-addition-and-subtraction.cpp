class Solution {
public:
    string fractionAddition(string expression) {
        vector<int> denominators;
        vector<int> numerators;
        vector<char> signs;
        int i=0;
        if(expression[i]=='-')
        {
            ++i;
            signs.push_back('-');
        }
        else
        signs.push_back('+');

        function<int(int,int)>gcd=[&](int num1,int num2)->int
        {
            return (num2==0) ? num1 : gcd(num2,num1%num2);
        };
        
        while(i<expression.size())
        {
            int num=0,denom=0;
            bool isNegative=(signs.back()=='-');

            while(i<expression.size() && isdigit(expression[i]))
            {
                num=num*10+(expression[i]-'0');
                ++i;
            }

            if(isNegative)
            num=-num;

            ++i;

            while(i<expression.size() && isdigit(expression[i]))
            {
                denom=denom*10+(expression[i]-'0');
                ++i;
            }

            numerators.push_back(num);
            denominators.push_back(denom);

            if(i<expression.size())
            {
                signs.push_back(expression[i]);
                ++i;
            }
        }

        int resultNum=numerators.front();
        int resultDenom=denominators.front();

        for(int j=1;j<numerators.size();++j)
        {
            int lcm=(resultDenom*denominators[j])/gcd(resultDenom,denominators[j]);
            resultNum=resultNum*(lcm/resultDenom)+numerators[j]*(lcm/denominators[j]);
            resultDenom=lcm;
        }

        int commonDivisor=gcd(abs(resultNum),abs(resultDenom));
        resultNum/=commonDivisor;
        resultDenom/=commonDivisor;

        if(resultDenom<0)
        {
            resultNum=-resultNum;
            resultDenom=-resultDenom;
        }

        return to_string(resultNum)+"/"+to_string(resultDenom);
    }
};