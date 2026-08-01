class Solution {
public:
/*
[2,1,4,1,1,1,1]
*/
    int jump(vector<int>& nums) {
        int l = 0;
        int r = 1;
        int jumps = 0;
        int end = nums.size();

        while (r < end) {
            int max_jump = 0;
            for (int i = l; i < r; i++) {
                if (nums[i] > max_jump) {
                    max_jump = nums[i];
                }
            }
            cout << max_jump << "\n";
            jumps++;
            int temp = r;
            r = r + max_jump;
            l = temp;
        }
        return jumps;
    }
};
