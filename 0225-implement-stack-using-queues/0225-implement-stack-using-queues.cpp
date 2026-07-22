class MyStack {
    queue<int>st;
public:
    MyStack() {
       
    }
    
    void push(int x) {
        st.push(x);
        for(int i=1;i<st.size();i++){
            st.push(st.front());
            st.pop();
        }
    }
    
    int pop() {
    int n= st.front();
    st.pop();
    return n;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
       return st.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */