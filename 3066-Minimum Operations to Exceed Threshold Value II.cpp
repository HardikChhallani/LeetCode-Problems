// T.C - O(n*log n) S.C - O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ops = 0;
        priority_queue<long,vector<long>,greater<long>> pq(begin(nums),end(nums)); // Heapify (log n)

        if(pq.top() >= k) return ops;

        while(!pq.empty() && pq.top()<k){ // O(n)
            long x = pq.top();
            pq.pop(); // O(log n)

            long y = pq.top();
            pq.pop(); // O(log n)

            pq.push(x*2 + y); // O(log n)
            ops++;
        }

        return ops;
    }
};
