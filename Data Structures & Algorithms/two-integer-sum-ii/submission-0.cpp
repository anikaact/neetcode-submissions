class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> diff;
        vector<int> result;

        for (int i = 0; i < numbers.size(); i++) {
            int difference = target - numbers[i];
            if (diff[difference]) {
                result.push_back(diff[difference]);
                result.push_back(i + 1);
                return result;
            } else {
                diff[numbers[i]] = i + 1;
            }
        }
        return result;
    }
};
