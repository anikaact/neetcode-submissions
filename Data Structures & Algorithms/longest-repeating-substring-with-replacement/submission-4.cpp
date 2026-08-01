class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int letters[26] = {0};
        int maxLen = 0;

        while (r < s.size() && l < s.size()) {
            letters[s[r] - 'A']++;
            int mostRepetitiveLetter = 0;
            for(int l : letters) mostRepetitiveLetter = max(mostRepetitiveLetter, l);
            if ((r - l - mostRepetitiveLetter + 1) <= k) {
                maxLen = max(maxLen, r - l + 1);
            } else {
                letters[s[l] - 'A']--;
                l++;
            }
            r++;
        }
        return maxLen;



/*
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int letters[26] = {0};
                int cur = i;
                while (cur <= j) {
                    letters[s[cur] - 'A']++;
                    cur++;
                }
                int mostRepetitiveLetter = 0;
                for(int l : letters) mostRepetitiveLetter = max(mostRepetitiveLetter, l);
                if ((j - i - mostRepetitiveLetter + 1) <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    */
    }
};
