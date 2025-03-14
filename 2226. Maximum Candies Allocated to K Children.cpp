// T.C => O(n*(log(maxCandies)))
// S.C => O(1)
class Solution {
public:
    typedef long long ll;
    bool isPossible(vector<int>& candies, long long k, ll mid){
        long long cnt = 0;
        for(int i=0; i<candies.size(); i++){
            cnt += candies[i]/mid;
            if(cnt >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll n = candies.size();
        long long ans = 0;

        ll left = 1;
        ll right = accumulate(candies.begin(), candies.end(), 0LL) / k;

        while(left <= right){
            ll mid = left + (right - left)/2;

            if(isPossible(candies,k,mid)){
                ans = mid;
                left = mid + 1;
            }
            else right = mid-1;
        }

        return ans;
    }
};
