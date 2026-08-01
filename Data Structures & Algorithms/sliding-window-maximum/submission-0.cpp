class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maximums;
        int left = 0;
        int right = k - 1;

        while (right < nums.size()) {
            //brute force: find max at every window
            int curmax = INT_MIN;
            int cur = left;
            while (cur <= right) {
                curmax = max(nums[cur], curmax);
                cur++;
            }
            maximums.push_back(curmax);
            left++;
            right++;
        }

        return maximums;
    }
};
