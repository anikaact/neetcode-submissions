class Solution {
public:
    int findMin(vector<int> &nums) {
        int right = nums.size() - 1;
        int left = 0;
        
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (abs(right - left) <= 1) return min(nums[left], nums[right]);

            if (nums[right] < nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};
