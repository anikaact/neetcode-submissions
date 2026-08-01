class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size());
        unordered_map<int, int> frequency;

        for (int n : nums) {
            frequency[n]++;
        }

        for (const auto &[num, count] : frequency) {
            buckets[count - 1].push_back(num);
        }

        vector<int> result;

        int index = buckets.size() - 1;
        while(k > 0) {
            if (!buckets[index].empty()) {
                for (int n : buckets[index]) {
                    result.push_back(n);
                    k--;
                }
                index--;
            } else {
                index--;
            }
        }

        return result;
    }
};
