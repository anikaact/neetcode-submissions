class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> numcount;

        for (int i : nums) {
            if (numcount.contains(i)) return i;
            numcount.insert(i);
        }

        return 0;
    }
};
