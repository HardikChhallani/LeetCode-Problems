class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(auto c : details){
            int age = (int(c[11])-48)*10+(int(c[12])-48);
            if(age>60) count++;
        }
        return count;
    }
};
