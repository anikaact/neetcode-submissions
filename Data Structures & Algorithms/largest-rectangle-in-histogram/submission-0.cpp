class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> heightStack; //start index, height

        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i];
            int start = i;
            while (!heightStack.empty() && heightStack.top().second > h) {
                //get data from top
                pair<int, int> cur = heightStack.top();
                heightStack.pop();
                int curInd = cur.first;
                int curHeight = cur.second;
                //change start, update max
                start = cur.first;
                maxArea = max(maxArea, (i - curInd) * curHeight);
            }
            //push to stack
            heightStack.push({start, h});
        }

        //rest of stack
        while(!heightStack.empty()) {
            int h = heightStack.top().second;
            int w = (heights.size()) - heightStack.top().first;
            maxArea = max(maxArea, h * w);
            heightStack.pop();
        }

        return maxArea;
    }
};
