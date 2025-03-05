// O(1)
class Solution {
public:
    long long coloredCells(int n) {
        long long n1 = 1LL*n*n;
        long long n2 = 1LL*(n-1)*1LL*(n-1);
        return n1+n2;
    }
};
