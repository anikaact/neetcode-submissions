class Solution {
public:
    int trap(vector<int>& height) {
        int maxArea = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            int leftMax = 0;
            int rightMax = 0;
            for (int l = 0; l < i; l++) {
                leftMax = max(height[l], leftMax);
            }
            for (int r = i+1; r < height.size(); r++) {
                rightMax = max(height[r], rightMax);
            }
            if (rightMax > height[i] && leftMax > height[i]) {
                maxArea += min(rightMax, leftMax) - height[i];
            }
        }

        return maxArea;
    }
};
