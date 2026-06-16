class Solution {
public:
    vector<int> parent, rank;
    int findUparent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUparent(parent[node]);
    }
    void unionbyRank(int u, int v){
        int pu = findUparent(u), pv = findUparent(v);
        if(pu == pv) return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rank[pv]++;
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int components = n;
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v=edges[i][1];
            if(findUparent(u) != findUparent(v)){
                unionbyRank(u,v);
                components--;
            }
        }
        return components;
    }
};