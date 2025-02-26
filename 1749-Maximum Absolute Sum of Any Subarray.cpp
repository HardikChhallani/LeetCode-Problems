// Kadane's Alogirthm - check karo ki i se naya subarray start kare ya fir curr 
// mein i ko add kare, aur uspe required condition lagao
// T.C - O(n)
// S.C - O(1)
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSubArraySum = nums[0], minSubArraySum = nums[0];
        int currMax = nums[0], currMin = nums[0];

        for(int i=1; i<n; i++){
            currMax = max(nums[i],currMax+nums[i]);
            maxSubArraySum = max(maxSubArraySum,currMax);
            currMin = min(nums[i],currMin+nums[i]);
            minSubArraySum = min(minSubArraySum,currMin);
        }

        return max(abs(minSubArraySum),abs(maxSubArraySum));
    }
};
