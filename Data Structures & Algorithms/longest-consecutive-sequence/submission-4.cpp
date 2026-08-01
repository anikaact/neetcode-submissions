class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //brute force solution: sort the array and then traverse through it
        //time: O(nlogn)
        if (nums.size() == 0) return 0;

        sort(nums.begin(), nums.end());

        int maxlen = 1;
        int cursize = 1;

        for (int i = 1; i < nums.size(); i++) {
            cout << nums[i] << ", ";
            if (nums[i] == nums[i - 1] + 1) {
                cursize++;
                maxlen = max(cursize, maxlen);
            } else if (nums[i] == nums[i - 1]) {
                continue;
            } else {
                cursize = 1;
            }
            cout << cursize << "\n";
        }

        return maxlen;

    }
};
