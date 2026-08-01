class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word: strs) {
            int key_arr[26] = {};
            for (char c: word) {
                key_arr[(c - 'a')]++;
            }

           string key;
            for (int num : key_arr) {
                std::cout << to_string(num);
                key += "#" + to_string(num);
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& pair : groups) {
        result.push_back(move(pair.second));
        }

        return result;

    }
};
