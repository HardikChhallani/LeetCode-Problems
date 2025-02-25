// Brute Force
// T.C - O(n^2)
// S.C - O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int subArrays = 0;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                if(sum%2 != 0) subArrays++;
            }
        }

        return subArrays;
    }
};

// Optimal
// T.C - O(n)
// S.C - O(1)
class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int subArrays = 0;
        int n = arr.size();

        int preSum = 0;
        int odd=0, even=1;

        for(int i=0; i<n; i++){
            preSum += arr[i];
            if(preSum%2 == 0){
                subArrays = (subArrays + odd) % MOD;
                even++;
            }
            else{
                subArrays = (subArrays + even) % MOD;
                odd++;
            }
        }

        return subArrays;
    }
};
