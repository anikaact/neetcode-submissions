class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int p1 = i + 1;
            int p2 = nums.size() - 1;
            int target = -nums[i];

            while (p1 < p2) {
                if (p1 == i) p1++;
                else if (p2 == i) p2--;
                else if (nums[p1] + nums[p2] == target) {
                    result.push_back({nums[i], nums[p1], nums[p2]});
                    // DUP CHECK 2: Skip identical elements for p1
                    while (p1 < p2 && nums[p1] == nums[p1 + 1]) p1++;
                    
                    // DUP CHECK 3: Skip identical elements for p2
                    while (p1 < p2 && nums[p2] == nums[p2 - 1]) p2--;

                    // Move both pointers inward to look for new potential pairs
                    p1++;
                    p2--;
                } else if (nums[p1] + nums[p2] > target) {
                    p2--;
                } else {
                    p1++;
                }
            }
        }

        return result;

    }
};
