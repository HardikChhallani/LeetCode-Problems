// T.C - (n)
// S.C - O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }

        for (const auto& entry : freq) {
            if (entry.second % 2 != 0) return false;
        }
        return true;
    }
};
