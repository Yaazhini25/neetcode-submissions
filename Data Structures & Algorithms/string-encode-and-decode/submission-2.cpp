class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s: strs){
            int len = s.size();
            ans+= to_string(len) + "#" + s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0, n=s.size();
        while(i<n){
            string tmp;
            string len;
            while(i<n && s[i]!='#') {len.push_back(s[i]); i++;}
            i++;
            for(int j=0; j<stoi(len); j++){
                tmp.push_back(s[i]);
                i++;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
