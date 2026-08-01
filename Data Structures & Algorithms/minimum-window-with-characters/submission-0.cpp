class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> letters(70);
        string result;
        int maxsize;

        for (char c : t) {
            letters[c - 'A']++;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                vector<int> contains = letters;
                int cur = i;
                while (cur <= j) {
                    contains[s[cur] - 'A']--;
                    cur++;
                }

                bool substring = true;
                for (int i : contains) {
                    if (i > 0) substring = false;
                }

                if (substring && (j - i) < maxsize) {
                    maxsize = j - i;
                    result = s.substr(i, maxsize + 1);
                }
            }
        }

        return result;
    }
};
