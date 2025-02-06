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


// Better approach O(n^3) & O(n)
class Solution {
public:
    typedef long long ll;
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int tuple = 0;
        sort(begin(nums),end(nums));

        for(int i=0; i<n; i++){
            for(int j=n-1; j>i; j--){
                ll p1 = 1LL*nums[i]*1LL*nums[j];
                unordered_set<int> st;
                for(int k=i+1; k<j; k++){
                    if(p1%nums[k] == 0){
                        int dval = p1/nums[k];
                        if(st.count(dval)>0){
                            tuple++;
                        }
                        st.insert(nums[k]);
                    }
                }
            }
        }
        return tuple*8;
    }
};


// Optimal approach O(n^2) & O(n)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                mpp[nums[i]*nums[j]]++;
            }
        }

        int tuples = 0;

        for(auto& it : mpp){
            if(it.second >= 2 ){
                int count = it.second;
                tuples += (count * (count-1))/2;
            }
        }

        return tuples*8;
    }
};
