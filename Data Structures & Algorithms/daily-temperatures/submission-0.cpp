class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int i=0, n=temperatures.size();
        vector<int> ans(n,0);
        while(i<n){
            if(st.empty()) st.push({i, temperatures[i]});
            else{
                while(!st.empty() && temperatures[i]>st.top().second){
                    ans[st.top().first] = i-st.top().first;
                    st.pop();
                }
                st.push({i,temperatures[i]});
            }
            i++;
        }
        return ans;
    }
};
