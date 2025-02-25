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
