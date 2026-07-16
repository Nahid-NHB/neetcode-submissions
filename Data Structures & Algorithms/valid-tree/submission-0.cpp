class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1){
            return false;
        }

        vector<vector<int>>adj(n);
        for(auto & e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        unordered_set<int>visit;
        if(!dfs(0,-1,visit, adj))return false;
        return visit.size()==n;
    }

    bool dfs(int node,int parent, unordered_set<int>& visit, vector<vector<int>>&adj)
    {
        if(visit.count(node))return false;
        visit.insert(node);
        for(int n:adj[node]){
            if(n==parent)continue;
            if(!dfs(n,node,visit,adj))return false;
        }
        
    return true;
    }

};
