class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        string res(n,'0');

        for(int i=0; i<m; i++){
            string it = nums[i];
            
            res[i] = (it[i] == '0') ? '1' : '0';
        }

        return res;
    }
};
