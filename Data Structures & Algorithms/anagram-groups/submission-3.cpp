class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> sublists;

        for (string s : strs) {
            array<int, 26> letters = {0};
            for (char c : s) {
                letters[c - 'a']++;
            }
            sublists[letters].push_back(s);
        }

        vector<vector<string>> result;

        for(const auto &[a, b] : sublists) {
            result.push_back(b);
        }

        return result;
    }
};
