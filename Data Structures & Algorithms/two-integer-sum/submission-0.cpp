#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> result = {0, 0};

        for (int i = 0; i , nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                result = {seen.at(complement), i};
                return result;
            }
            seen.insert({nums[i], i});
        }
        return result;
    }
};
