class Solution {
public:
    string numberToWords(int num) {
        if(num==0)
        return "Zero";

        vector<string> lessThanTwenty={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fouteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> tensPlaces={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};

        auto twoDigit=[&](int num)
        {
            if(num<20)
            return lessThanTwenty[num];
            else
            {
                int tens=num/10;
                int ones=num%10;
                return tensPlaces[tens]+(ones==0 ? "" : " "+lessThanTwenty[ones]);
            }
        };

        auto threeDigit=[&](int num)
        {
            if(num==0)
            return string("");
            if(num<100)
            return twoDigit(num);
            return lessThanTwenty[num/100]+" Hundred"+(num%100==0 ? "" : " "+twoDigit(num%100));
        };

        int billion=num/1000000000;
        int million=(num/1000000)%1000;
        int thousand=(num/1000)%1000;
        int hundred=num%1000;

        string result;
        if(billion)
        result+=threeDigit(billion)+" Billion";
        if(million)
        result+=(result.empty() ? "" : " ")+threeDigit(million)+" Million";
        if(thousand)
        result+=(result.empty() ? "" : " ")+threeDigit(thousand)+" Thousand";
        if(hundred)
        result+=(result.empty() ? "" : " ")+threeDigit(hundred);

        return result;
    }
};