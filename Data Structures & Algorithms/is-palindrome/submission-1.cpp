class Solution {
public:
    
    bool isPalindrome(string s) {
        string ss;
        for(auto i: s){
            char tmp = tolower(i);
            if((tmp>=97 && tmp<=122) || (tmp>=48 && tmp<=57)) ss.push_back(tmp);
        }
        
        int l=0, r=ss.size()-1;
        while(l<r){
            if(ss[l] != ss[r]) return false;
            l++; r--;
        }

        return true;
    }
};
