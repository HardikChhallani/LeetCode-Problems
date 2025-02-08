class NumberContainers {
public:
    unordered_map<int,int> mpp;  // index -> number
    unordered_map<int,set<int>> st;  // number -> set<index>
    NumberContainers() {}
    
    void change(int index, int number) {
        if(mpp.count(index)){
            int oldNum = mpp[index];
            st[oldNum].erase(index);
            if(st[oldNum].empty()) st.erase(oldNum);
        }

        mpp[index] = number;
        st[number].insert(index);
    }

    
    int find(int number) {
        if(st.find(number) != st.end()){
            return *st[number].begin();
        }
        return -1;
    }
};
