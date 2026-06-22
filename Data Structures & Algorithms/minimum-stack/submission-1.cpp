class MinStack {
public:
    stack<int> mono;
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mono.empty()) mono.push(val);
        else{
            if(val <= mono.top()) mono.push(val);
        }
    }
    
    void pop() {
        if(st.top() == mono.top()) mono.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mono.top();
    }
};
