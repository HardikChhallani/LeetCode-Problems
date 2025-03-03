// T.C - O(n)
// S.C - O(n)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> lessPivot;
        vector<int> morePivot;
        int pivotCnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == pivot) pivotCnt++;
            else if(nums[i] < pivot) lessPivot.push_back(nums[i]);
            else morePivot.push_back(nums[i]);
        }

        vector<int> res;
        for(int i : lessPivot) res.push_back(i);

        while(pivotCnt){
            res.push_back(pivot);
            pivotCnt--;
        }

        for(int i : morePivot) res.push_back(i);

        return res;
    }
};
