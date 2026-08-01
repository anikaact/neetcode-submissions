class Solution {
public:
/*
[1, 2, 0, 1, 0]
[1, 3, 2, 4, 0]
[1, 1, 1, 1, 1]
[1,2,1,0,1]
[1,3,4,3,1]

[1, 2, 3, 1, 0, 0]
[1, 3, 5, 4, 0 ,0]

*/
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
            if (farthest >= nums.size() - 1) return true;
        }

        return true;
    }
};
