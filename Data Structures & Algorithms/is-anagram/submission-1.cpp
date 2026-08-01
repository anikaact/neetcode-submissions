class Solution {
public:
    bool isAnagram(string s, string t) {
        int letters[26] = {0};

        for (char c : s) {
            letters[c - 'a']++;
        }

        for (char c : t) {
            letters[c - 'a']--;
        }

        for (int i : letters) {
            if (i != 0) return false;
        }

        return true;
    }
};
