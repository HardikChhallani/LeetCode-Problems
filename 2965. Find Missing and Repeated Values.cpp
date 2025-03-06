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

// T.C - O(n^2)
// S.C - O(1)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> st;

        int a=0, b=0;
        int n = grid.size();
        long long N = n*n;

        long long sum = (N*(N+1)/2), gridSum = 0;
        long long sqSum = (N*(N+1)*(2*N+1)/6), gridSqSum = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                gridSum += grid[i][j];
                gridSqSum += (grid[i][j] * grid[i][j]);
            }
        }

        int sqSumDiff = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;

        a = ((sqSumDiff/sumDiff) + sumDiff)/2;
        b = ((sqSumDiff/sumDiff) - sumDiff)/2;
        return {a,b};
    }
};
