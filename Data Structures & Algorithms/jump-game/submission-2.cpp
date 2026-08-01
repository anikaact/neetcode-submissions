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
        if (nums.size() == 1) {
            return true;
        }

        int can_reach[nums.size()];
        can_reach[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (can_reach[i] == 1) {
                for (int j = 0; (j <= nums[i]) && ((j + i) < nums.size()); j++) {
                    can_reach[i + j] = 1;
                }
            }
        }

        return can_reach[nums.size() - 1] == 1;
    }
};
