class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;

        vector<int> leftMax(height.size());
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }

        vector<int> rightMax(height.size());
        for (int i = height.size() - 2; i > 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }

        int maxArea = 0;
        for (int i = 0; i < height.size(); i++) {
            //cout << leftMax[i] << ", " << rightMax[i] << "\n";
            if (leftMax[i] > height[i] && rightMax[i] > height[i]) {
                maxArea += min(leftMax[i], rightMax[i]) - height[i];
            }
        }

        return maxArea;
    }
};
