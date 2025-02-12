// O(n*d) & O(n)
class Solution {
public:
    int findSumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num%10;
            num = num/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        int res = -1;

        for(int& num : nums){ //O(n)
            int sum = findSumOfDigits(num); //O(d)
            if(mpp.count(sum)){
                res = max(res, num + mpp[sum]);
            }
            mpp[sum] = max(mpp[sum],num);
        }
        
        return res;
    }
};
