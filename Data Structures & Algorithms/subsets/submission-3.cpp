class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int>& path, int index) {
        //base base
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        //explore
        backtrack(nums, path, index + 1);
        path.push_back(nums[index]);
        backtrack(nums, path, index + 1);

        //backtrack
        erase(path, nums[index]);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path = {};
        backtrack(nums, path, 0);
        return res;
    }
};
