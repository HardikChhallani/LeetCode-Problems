// T.C - O(n*3*2^(n-1)) === O(n*2^n)
// S.C - O(n)
class Solution {
public:
    int cnt = 0;
    void solve(int n, int k, string& res, string& ans){
        if(res.size() == n){
            cnt++;
            if(cnt == k)
                ans = res;
            return ;
        }

        for(char i='a'; i<='c'; i++){
            if(cnt == k) return ;
            if(res.empty() || res.back() != i){
                res.push_back(i);
                solve(n,k,res,ans);
                res.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string ans = "";
        string res;
        solve(n,k,res,ans);
        return ans;
    }
};
