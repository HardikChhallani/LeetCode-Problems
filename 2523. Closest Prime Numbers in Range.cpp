// T.C - O((R-L)*sqrt(R))
// S.C - O(1)
class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;

        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int prevPrime = -1;
        int num1 = -1, num2 = -1;
        int diff = INT_MAX;

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prevPrime != -1 && (i - prevPrime) < diff) {
                    diff = i - prevPrime;
                    num1 = prevPrime;
                    num2 = i;
                }
                prevPrime = i;
            }
        }
        
        return {num1,num2};
    }

};
