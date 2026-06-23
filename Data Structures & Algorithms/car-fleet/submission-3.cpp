class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> st;
        int n=position.size();
        for(int i=0; i<n; i++){
            st.push_back({position[i], (double)(target-position[i])/speed[i]});
        }
        sort(st.begin(), st.end());
        stack<pair<int,double>> ss;
        for(int i=n-1; i>=0; i--){
            if(ss.empty()) ss.push(st[i]);
            else{
                if(st[i].second > ss.top().second) ss.push(st[i]);
            }
        }
        return ss.size();
    }
};
