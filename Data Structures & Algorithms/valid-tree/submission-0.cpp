class Solution {
public:
    vector<int> rank, parent;
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
    bool validTree(int n, vector<vector<int>>& edges) {
        rank.resize(n, 1);
        parent.resize(n);
        for(int i=0; i<n; i++) parent[i] = i;
        if(edges.size() != n-1) return false;
        for(int i=0; i<n-1; i++){
            int u=edges[i][0], v=edges[i][1];
            if(findUparent(u) == findUparent(v)) return false;
            unionbyRank(u,v);
        }
        return true;
    }
};
