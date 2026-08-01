class Solution {
public:
    int findMin(vector<int> &nums) {
        int right = nums.size() - 1;
        int left = 0;
        
        while (left < right) {
            int mid = (right + left) / 2;
            cout << left << ", " << right << ", " << mid << "\n";

            if (abs(right - left) <= 1) return min(nums[left], nums[right]);

            if (nums[right] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return nums[right];
    }
};
