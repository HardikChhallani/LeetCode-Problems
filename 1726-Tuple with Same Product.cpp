// Brute Force Approach - O(n⁴)
class Solution {
public:
    typedef long long ll;
    int findTuples(vector<int>& nums, int idx1, int idx2, ll product){
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(idx1 == i) continue;
            for(int j=i+1; j<n; j++){
                if(idx2 == j) continue;
                if(product == 1LL*nums[i]*nums[j]) cnt++;
            }
        }
        return cnt*2;
    }

    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(i == j) continue;
                ll product = nums[i]*nums[j];
                cnt += findTuples(nums,i,j,product);
            }
        }

        return cnt*2;
    }
};
