class Solution {
public:
    bool issym(string s){
        return s=="+" || s=="-" || s=="*" || s=="/";
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans=0;
        for(auto i: tokens){
            if(!issym(i)) st.push(stoi(i));
            else{
                int n2=st.top(); st.pop();
                int n1=st.top(); st.pop();
                if(i=="+") st.push(n1+n2);
                else if(i=="-") st.push(n1-n2);
                else if(i=="*") st.push(n1*n2);
                else st.push(n1/n2);
            }
        }
        return st.top();
    }
};
