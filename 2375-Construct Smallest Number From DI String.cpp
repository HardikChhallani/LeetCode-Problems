// Brute Force
// T.C - O(n*n!)
// S.C - O(n)
class Solution {
public:
    void nextPermutation(string& nums){
        int n = nums.size();

        int idx = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]-'0' < nums[i+1]-'0'){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return ;
        }

        for(int i=n-1; i>idx; i--){
            if(nums[i]-'0' > nums[idx]-'0'){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+idx+1,nums.end());
    }

    bool matchesPattern(string& nums, string& pattern){
        for(int i=0; i<pattern.size(); i++){
            if((pattern[i] == 'I' && nums[i] > nums[i+1]) ||
                (pattern[i] == 'D' && nums[i] < nums[i+1]))
                    return false;
        }
        return true;
    }
    string smallestNumber(string pattern) {
        int n = pattern.size();

        string nums = "";
        for(int i=1; i<=n+1; i++)
            nums.push_back(i+'0');

        while(!matchesPattern(nums,pattern)){
            nextPermutation(nums);
            cout<<nums<<endl;
        }

        return nums;
    }
};

// Optimal Code
// T.C - O(n)
// S.C - O(n)
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string num = "";

        int cnt = 1;
        stack<char> st;

        for(int i=0; i<=n; i++){
            st.push(cnt+'0');
            cnt++;

            if(i==n || pattern[i] == 'I'){
                while(!st.empty()){
                    num += st.top();
                    st.pop();
                }
            }
        }
        return num;
    }
};
