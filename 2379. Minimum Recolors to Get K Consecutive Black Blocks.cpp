// T.C - O(k) + O(n-k) => O(N)
// S.C - O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int recolor = 0;
        int n = blocks.length();
        int left = 0, right = k-1;
        
        for(int i=left; i<=right; i++){
            if(blocks[i] == 'W') recolor++;
        }

        int minRecolor = recolor;
        while(right < n-1){
            if(blocks[left] == 'W') recolor--;
            left++;
            right++;
            if (blocks[right] == 'W') recolor++;

            minRecolor = min(minRecolor, recolor);
        }

        return minRecolor;

    }
};
