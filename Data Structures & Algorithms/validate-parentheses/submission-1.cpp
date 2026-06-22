class Solution {
public:
    bool ismatch(char a, char b){
        if((a=='(' && b==')') || (a=='[' && b==']') || (a=='{' && b=='}')) return true;
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c: s){
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else{
                if(st.empty()) return false;
                else if(!ismatch(st.top(), c)) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
