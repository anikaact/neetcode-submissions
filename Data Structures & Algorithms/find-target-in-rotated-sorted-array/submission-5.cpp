class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int pivot = 0;

        //find pivot (greatest number)
        while (l < r) {
            int mid = ((r - l) / 2) + l;

            if (nums[l] > nums[mid]) {
                r = mid;
            } else if (nums[mid + 1] > nums[r]) {
                l = mid + 1;
            }
            else {
                l = mid;
                break;
            }
        }
        pivot = l;

        //binary search using pivot
        l = 0;
        r = nums.size() - 1;

        //either search left or right side
        if (target >= nums[l] && target <= nums[pivot]) {
            r = pivot;
        } else {
            l = pivot + 1;
        }

        //normal binary search
        while (l <= r) {
            int mid = ((r - l) / 2) + l;

            if (nums[mid] == target) return mid;

            if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
};
