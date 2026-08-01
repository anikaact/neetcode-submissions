class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for (int i = 0; i < temperatures.size(); i++) {
            int t = temperatures[i];
            while (!s.empty() && t > s.top().first) {
                auto p = s.top();
                s.pop();
                res[p.second] = i - p.second;
            }
            s.push({t, i});
        }
        return res;
    }
};
