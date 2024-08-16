class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        return (n%2==0) ? isPowerOfTwo(n/2) : n==1;
    }
};