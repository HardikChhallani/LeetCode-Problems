// Using C++ STL
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int P = count_if(nums.begin(),nums.end(),[](int n){ return n>0;});
        int N = count_if(nums.begin(),nums.end(),[](int n){ return n<0;});
        return max(P,N);
    }
};

// -----------------------------------------------------------------------------------------------------

// T.C - O(2*log(n)) => O(log(n))
// S.C - O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int n = nums.size();
       int left=0, right = n-1;

       int firstPosIdx = n;
       while(left <= right){
        int mid = left + (right-left)/2;

        if(nums[mid] > 0){
            firstPosIdx = mid;
            right = mid - 1;
        }
        else left = mid+1;
       }

       left=0, right = n-1;

       int lastNegIdx = -1;
       while(left <= right){
        int mid = left + (right-left)/2;

        if(nums[mid] < 0){
            lastNegIdx = mid;
            left = mid + 1;
        }
        else right = mid - 1;
       }

       if (lastNegIdx == -1 && firstPosIdx == n) return 0; // All zeros
        if (firstPosIdx == n) return lastNegIdx + 1; // All negative
        if (lastNegIdx == -1) return n - firstPosIdx; // All positive
        return max(lastNegIdx + 1, n - firstPosIdx);
    }
};
