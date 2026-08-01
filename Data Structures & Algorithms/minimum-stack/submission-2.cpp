class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        //initialize stack object
        st = {};
    }
    
    void push(int val) {
        st.push(val);
        if (!minst.empty()) {
            val = min(val, minst.top());
        }
        minst.push(val);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
