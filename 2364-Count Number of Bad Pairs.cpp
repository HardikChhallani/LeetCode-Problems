// O(n) & O(n)
class Solution { 
public:
    typedef long long ll;
    long long countBadPairs(vector<int>& nums) {
        unordered_map<ll,ll> mpp;
        ll n = nums.size();
        for(int i=0; i<n; i++){
            ll diff = (i - nums[i]);
            mpp[diff]++;
        }


        ll totalPairs = (n*(n-1)/2);
        cout<<totalPairs<<endl;
        ll nonBadPairs = 0;
        for(auto& it : mpp){
            cout<<it.first<<" -> "<<it.second<<endl;
            ll p = it.second;
            nonBadPairs += p*(p-1)/2;
        }
        cout<<nonBadPairs<<endl;
        return totalPairs - nonBadPairs;
    }
};
