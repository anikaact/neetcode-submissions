class Solution {
public:
/*
[2,-3,4,-2,2,1,-1,4]
*/
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0];
        int maxval = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            maxval = max(cur, maxval);
        }
        
        return maxval;
    }
};
