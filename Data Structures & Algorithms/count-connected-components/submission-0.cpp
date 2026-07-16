class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(n);
        vector<bool>visit(n,false);
        
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int r=0;
        for(int node=0;node<n;node++){
            if(!visit[node]){
                dfs(adj,visit,node);
                r++;
            }
        }
        return r;
    }

void dfs(const vector<vector<int>>& adj, vector<bool>& visit, int node) {
        visit[node] = true;
        for (int nei : adj[node]) {
            if (!visit[nei]) {
                dfs(adj, visit, nei);
            }
        }
    }

};
