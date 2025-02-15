// Recursion based approach 
// T.C - O(n*(2^log(n^2)))
// S.C - O(n*(log(n^2)) + O(log(n^2))
class Solution {
public:
    bool check(int i, int currSum, string s, int num,vector<vector<int>>& t){
        if(i == s.length()) return currSum == num;
        if(currSum > num) return false;

        if(t[i][currSum] != -1) return t[i][currSum];
        
        bool possible = false;
        for(int j=i; j<s.length(); j++){
            string temp = s.substr(i,j-i+1);
            int val = stoi(temp);

            possible = possible || check(j+1,currSum+val,s,num,t);

            if(possible == true) return true;
        }

        return t[i][currSum] = possible;
    }
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num=1; num<=n; num++){
            int sq = num*num;
            string s = to_string(sq);
            vector<vector<int>> t(s.length(),vector<int>(num+1,-1));

            if(check(0,0,s,num,t))
                punish += sq;
        }
        
        return punish;
    }
};

// Optimal 
// T.C - O(n*(2^log(n^2)))
// S.C - O(log(n^2))
class Solution {
public:
    bool check(int sq, int currSum, int num){
        if(sq == 0)
            return currSum == num;

        return check(sq/10,currSum+(sq%10),num) ||
               check(sq/100,currSum+(sq%100),num) ||
               check(sq/1000,currSum+(sq%1000),num) ||
               check(sq / 10000, currSum + sq % 10000, num);
    }
    int punishmentNumber(int n) {
        int punish = 0;

        for(int num=1; num<=n; num++){
            int sq = num*num;

            if(check(sq,0,num))
                punish += sq;
        }
        
        return punish;
    }
};
