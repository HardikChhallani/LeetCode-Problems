// Brute Force
// T.C - O(n^2)
// S.C - O(1)
class Solution {
public:
    bool isVowel(char& c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long beautifulSubstrings(string s, int k) {
        
        int n = s.size();

        int beauty = 0;
        for(int i=0; i<n; i++){
            int vowels = 0;
            int cons = 0;
            for(int j=i; j<n; j++){
                if(isVowel(s[j])) vowels++;
                else cons++;
                if(vowels != 0 && vowels == cons && (vowels*cons)%k == 0){
                    beauty++;
                }
            }
        }

        return beauty;
    }
};
