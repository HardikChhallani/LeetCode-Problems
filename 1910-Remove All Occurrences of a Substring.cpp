// Using builtin functions
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.length() >= s.find(part)){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
//Using Stack O(n*m) && O(m+m)
class Solution {
public:
    bool findOccurence(stack<char>& st, string part){
        int m = part.length();
        stack<char> temp = st;
        for(int i=m-1; i>=0; i--){
            if(part[i] != temp.top()) return false;
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        stack<char> st;
        
        for(char c : s){
            st.push(c);

            if(st.size() >= m && findOccurence(st,part)){
                for(int i=0; i<m; i++)
                    st.pop();
            }
        }

        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(begin(ans),end(ans));
        return ans;
    }
};

//Without using stack O(n*m) && O(m)
class Solution {
public:
    bool findOccurence(string ans, string part){
        int m = part.length();
        for(int i=m-1; i>=0; i--){
            if(part[i] != ans.back()) return false;
            ans.pop_back();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int n = s.size(), m = part.size();
        string ans;
        
        for(char c : s){
            ans.push_back(c);

            if(ans.size() >= m && findOccurence(ans,part)){
                for(int i=0; i<m; i++)
                    ans.pop_back();
            }
        }

        return ans;
    }
};
