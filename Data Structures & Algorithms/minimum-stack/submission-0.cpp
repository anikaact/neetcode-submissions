class MinStack {
public:
    vector<int> st;
    MinStack() {
        //initialize stack object
        st = {};
    }
    
    void push(int val) {
        st.push_back(val);
    }
    
    void pop() {
        st.erase(st.end());
    }
    
    int top() {
        return st[st.size() - 1];
    }
    
    int getMin() {
        int min = INT_MAX;
        for (int i : st) {
            if (i < min) min = i;
        }
        return min;
    }
};
