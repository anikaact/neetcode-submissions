class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& nums, vector<int> path, int index) {
        //base base
        if (index == nums.size()) {
            res.push_back(path);
            return;
        }

        //choose (index)
        vector<int> include = path;
        include.push_back(nums[index]);
        index++;

        //explore
        backtrack(nums, path, index);
        backtrack(nums, include, index);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, {}, 0);
        return res;
    }
};
