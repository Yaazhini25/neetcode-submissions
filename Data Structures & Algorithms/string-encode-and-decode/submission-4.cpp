class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(auto i: strs){
            ans+= to_string(i.size())+"#"+i;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0, n=s.size();
        while(i<n){
            int num=0;
            while(i<n && isdigit(s[i])) {
                num = num*10 + (s[i]-'0');
                i++;
            }
            i++;
            string tmp="";
            while(i<n && num>0){
                tmp+=s[i];
                i++;
                num--;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
