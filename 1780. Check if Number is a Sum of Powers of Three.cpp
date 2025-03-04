// T.C - O(log3(n))
// S.C - O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {
        int p = 0;
        while(pow(3,p) <= n) p++;

        while(n > 0){
            if(n >= pow(3,p))
                n = n - pow(3,p);

            if(n >= pow(3,p)) return false;

            p--;
        }

        return true;
    }
};

// T.C - O(log3(n))
// S.C - O(1)
class Solution {
public:
    bool checkPowersOfThree(int n) {

        while(n > 0){
            if(n%3 > 1) return false;
            n /= 3;
        }

        return true;
    }
};
