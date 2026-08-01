class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } 

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

         vector<int> maxmoney;

        maxmoney.push_back(nums[0]);
        maxmoney.push_back(nums[1]);
        maxmoney.push_back(nums[2] + nums[0]);

        for (int i = 3; i < nums.size(); i++) {
            maxmoney.push_back(nums[i] + max(maxmoney[i-2], maxmoney[i-3]));
        }

        return max(maxmoney[maxmoney.size() - 1], maxmoney[maxmoney.size() - 2]);
        
    }
};
/*
3 2 8 9 2 4
3 + 9 + 4 = 16
3 + 8 + 2 = 13

3 4 11 12 13 16
*/