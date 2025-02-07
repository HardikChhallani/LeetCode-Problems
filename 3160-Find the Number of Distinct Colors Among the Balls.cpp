// O(n) & O(n+n) => O(n)
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> res;

        unordered_map<int,int> ballArr; // ball - color
        unordered_map<int,int> freq; // color - count

        for(auto& q : queries){            
            int ball = q[0], color = q[1];

            if(ballArr.count(ball)){
                freq[ballArr[ball]]--;
                if(freq[ballArr[ball]] == 0)
                    freq.erase(ballArr[ball]);
            }

            ballArr[ball] = color;
            freq[color]++;
            res.push_back(freq.size());
        }

        return res;
    }
};
