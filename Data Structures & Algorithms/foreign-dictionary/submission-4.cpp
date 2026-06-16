class Solution {
public:
    void toposort(vector<vector<int>> &adj, string &ans, vector<int> &present, int &cnt){
        vector<int>indegree(26,0);
        for(int i=0; i<26; i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0; i<26; i++){
            if(indegree[i] == 0 && present[i]) q.push(i);
        }
        while(!q.empty()){
            int node = q.front(); q.pop();
            ans.push_back('a'+node);
            cnt++;
            for(auto &neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
        }
    }
    string foreignDictionary(vector<string>& words) {
        if(words.size() == 1) return words[0];
        string ans="";
        vector<vector<int>> adj(26);
        vector<int> present(26,0);

        //adj construction
        int ind=1;
        while(ind<words.size()){
            string s1=words[ind-1], s2=words[ind];
            int i=0,j=0;
            while(i<s1.size() && j<s2.size()){
                present[s1[i]-'a']=1; present[s2[j]-'a'] = 1;
                if(s1[i] != s2[j]){
                    adj[s1[i]-'a'].push_back(s2[j]-'a');
                    break;
                }
                i++; j++;
                if(i<s1.size() && j==s2.size()) return "";
            }
            while(i<s1.size()){
                present[s1[i]-'a']=1;
                i++;
            } 
            while(j<s2.size()){
                present[s2[j]-'a']=1;
                j++;
            }
            ind++;
        }
        int cnt=0;
        toposort(adj,ans, present, cnt);

        //cycle detection
        int total = 0;
        for(auto &i: present){
            if(i) total++;
        }
        if(cnt != total) return "";
        return ans;
    }
};
