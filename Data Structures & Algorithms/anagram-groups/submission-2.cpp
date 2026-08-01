class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> anagrams;

        for (int i = 0; i < strs.size(); i++) {
            vector<int> count(26, 0);
            for (char c : strs[i]) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            anagrams[key].push_back(strs[i]);
        }

        for (const auto& pair : anagrams) {
            result.push_back(pair.second);
        }

        return result;
    }
};
