// Brute force O(n^2)
class Solution {
public:
    string clearDigits(string s) {
        int i=0;

        while(i < s.size()){
            if(isdigit(s[i])){
                s.erase(i,1);
                if(i>0){
                    s.erase(i-1,1);
                    i--;
                }
            }
            else i++;
        }
        return s;
    }
};
//Using stack
class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;

        for(char c : s){
            if(isdigit(c)){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(c);
            }
        }

        string ans;
        while(!st.empty()){
            char c = st.top();
            st.pop();
            ans += c;
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};
//Without using stack with time - O(n) and space O(n)
class Solution {
public:
    string clearDigits(string s) {
        string ans;

        for(char c : s){
            if(isdigit(c)){
                if(ans.size() != 0) ans.pop_back();
            }
            else ans.push_back(c);
        }

        return ans;
    }
};
// O(n) & o(1)
class Solution { 
public:
    string clearDigits(string s) {
        int i=0, j=0;

        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                j = max(0,j-1);
            }
            else{
                s[j] = s[i];
                j++;
            }
        }
        
        if(j == 0) return "";
        return s.substr(0,j);
    }
};
