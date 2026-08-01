class MinStack {
public:
    vector<int> st;
    stack<int> minst;
    MinStack() {
        //initialize stack object
        st = {};
    }
    
    void push(int val) {
        st.push_back(val);
        if (!minst.empty()) {
            val = min(val, minst.top());
        }
        minst.push(val);
    }
    
    void pop() {
        st.erase(st.end());
        minst.pop();
    }
    
    int top() {
        return st[st.size() - 1];
    }
    
    int getMin() {
        return minst.top();
    }
};
