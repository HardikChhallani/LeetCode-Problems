// Single Pass solution
// T.C - O(n)
// S.C - O(1)
class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for(int i=0; i<n; i++){
            if(i+1<n && nums[i] == nums[i+1]){
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
            if(nums[i] != 0){
                swap(nums[j],nums[i]);
                j++;
            }
        }

        return nums;
    }
};
