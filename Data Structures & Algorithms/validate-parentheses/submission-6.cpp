class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (!st.empty() && st.top() == closeToOpen[c]) {
                st.pop();
            } else {
                st.push(c);
            }
        }

        return st.empty();
    }
};
