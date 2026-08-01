class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        vector<int> prefix;
        vector<int> suffix;
        int pre = 1;
        int suf = 1;

        for (int i = 0; i < nums.size(); i++) {
            pre *= nums[i];
            prefix.push_back(pre);
            suf *= nums[nums.size() - i - 1];
            suffix.push_back(suf);
        }

        vector<int> result;

//condition
        result.push_back(suffix[nums.size() - 2]);

        //nums: [1, 2, 4, 6]
        //pre: [1, 2, 8, 42]
        //suf: [6, 24, 48, 48]
        //result: [48, 24, 12, 8]
        for (int i = 1; i < nums.size() - 1; i++) {
            result.push_back(prefix[i - 1]*suffix[nums.size() - i - 2]);
        }

//condition
        result.push_back(prefix[nums.size() - 2]);
        return result;
    }
};
