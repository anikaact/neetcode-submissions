class Solution {
public:
        vector<vector<int>> result;
        vector<int> subset;
        int sum = 0;
    
        void backtrack(vector<int>& nums, int index, int target) {
            if (sum == target) {
                result.push_back(subset);
                return;
            }
            if (sum > target) {
                return;
            }
            for (int i = index; i < nums.size(); i++) {
                subset.push_back(nums[i]);
                sum += nums[i];
                backtrack(nums, i, target);
                subset.pop_back();
                sum -= nums[i];
            }
        }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(nums, 0, target);
        return result;

    }
};
