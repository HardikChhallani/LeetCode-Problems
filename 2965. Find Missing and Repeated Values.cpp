// T.C - O(n^2)
// S.C - O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;

        int a=0, b=0;
        int n = grid.size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(st.count(grid[i][j]) > 0) a = grid[i][j];
                st.insert(grid[i][j]);
            }
        }

        for(int i=1; i<=n*n; i++){
            if(st.count(i) == 0) b = i;
        }

        return {a,b};
    }
};
