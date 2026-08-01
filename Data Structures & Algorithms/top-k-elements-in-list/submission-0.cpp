class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;

        for (int num: nums) {
            frequency[num]++;
        }

        // 2) Buckets: index = frequency, value = list of numbers with that freq
        // Max possible frequency is nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto& [num, f] : frequency) {
            buckets[f].push_back(num);
        }

        vector<int> result;
        result.reserve(k);
        for (int f = (int)nums.size(); f >= 1 && (int)result.size() < k; --f) {
            for (int num : buckets[f]) {
                result.push_back(num);
                if ((int)result.size() == k) break;
            }
        }
        return result;
    }
};
