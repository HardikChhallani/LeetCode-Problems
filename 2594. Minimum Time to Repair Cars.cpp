# Solve
class Solution {
public:
    typedef long long ll;
    long long findCars(vector<int>& ranks, ll mid){
        ll cars = 0;
        for(int& r : ranks){
            cars += sqrt(mid/r);
            if (cars >= LLONG_MAX) break;
        }
        return cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        ll n = ranks.size();
        ll minRank = *min_element(ranks.begin(),ranks.end());

        ll left = 1, right = 1e18;
        ll ans = LLONG_MAX;

        while(left <= right){
            ll mid = left + (right - left)/2;

            if(findCars(ranks,mid) >= cars){
                ans = mid;
                right = mid-1;
            }
            else left = mid+1;
        }

        return ans;
    }
};
