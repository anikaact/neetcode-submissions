class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numbers;

        for (int i = 0; i < nums.size(); i++) {
            int remainder = target - nums[i];
            if (numbers[remainder]) {
                return {numbers[remainder] - 1, i};
            } else {
                numbers[nums[i]] = i + 1;
            }
        }

        return {};
    }
};
