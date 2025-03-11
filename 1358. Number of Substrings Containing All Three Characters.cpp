// O(2n) => O(n)
// O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i=0,j=0;

        map<char,int> mp;
        int res = 0;
        while(j<n){
            mp[s[j]]++;

            while(i<j && mp.size() == 3){
                res += n-j;

                mp[s[i]]--;
                if(mp[s[i]] == 0) mp.erase(s[i]);
                i++;
            }

            j++;
        }
        return res;
    }
};
