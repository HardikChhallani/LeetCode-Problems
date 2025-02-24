class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;

    bool DFSBob(int curr, int time, vector<bool>& visited){
        visited[curr] = true;
        bobMap[curr] = time;
        if(curr == 0) return true;

        for(auto& ngbr : adj[curr]){
            if(!visited[ngbr]){
                if(DFSBob(ngbr,time+1,visited)) return true;
            }
        }

        bobMap.erase(curr);
        return false;
    }

    void DFSAlice(int curr, int time, vector<bool>& visited, vector<int>& amount, int income){
        visited[curr] = true;

        if(bobMap.find(curr) == bobMap.end() || time < bobMap[curr]){
            income += amount[curr];
        } else if(time == bobMap[curr]){
            income += (amount[curr]/2);
        }
        
        if(adj[curr].size() == 1 && curr != 0) {
            aliceIncome = max(aliceIncome,income);
        }

        for(int& ngbr : adj[curr] ){
            if(!visited[ngbr]){
                DFSAlice(ngbr,time+1,visited,amount,income);
            }
        }

        visited[curr] = false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        aliceIncome = INT_MIN;
        int time = 0;
        vector<bool> visited(n,false);
        DFSBob(bob,time,visited);

        int income = 0;
        fill(visited.begin(), visited.end(), false);
        DFSAlice(0,0,visited,amount,income);
        return aliceIncome;
    }
};
