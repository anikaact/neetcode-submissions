class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        unordered_set<string> operators = {"+", "-", "*", "/"};
        for (string s : tokens) {
            if (!operators.contains(s)) {
                //is integer
                st.push(stoi(s));
            } else {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if (s == "+") st.push(a + b);
                if (s == "-") st.push(b - a);
                if (s == "*") st.push(a * b);
                if (s == "/") st.push(b / a);
            }
        }
        return st.top();
    }
};
