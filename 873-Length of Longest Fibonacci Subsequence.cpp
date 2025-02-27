// T.C - O(n^2)
// S.C - O(n)
class Solution {
public:
    int solve(int j, int k,vector<int>& arr,unordered_map<int,int>& mp,vector<vector<int>>& dp){
        int target = arr[k] - arr[j];
        if(dp[j][k] != -1) return dp[j][k];

        if(mp.count(target)>0 && mp[target]<j){
            dp[mp[target]][j] = 1 + solve(mp[target],j,arr,mp,dp);
            return dp[mp[target]][j];
        }

        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp; // {element -> index}
        for(int i=0; i<n; i++)
            mp[arr[i]] = i;
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,2));
        int res = 0;
        for(int j=1; j<n; j++){
            for(int k=j+1; k<n; k++){
                int target = arr[k] - arr[j];
                if(mp.count(target)>0 && mp[target]<j){
                    dp[j][k] = 1 + dp[mp[target]][j];
                }
                res = max(res,dp[j][k]);
            }
        }

        return res<3 ? 0 : res;
    }
};
