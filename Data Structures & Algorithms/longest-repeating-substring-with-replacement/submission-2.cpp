class Solution {
public:
    int characterReplacement(string s, int k) {
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
    }
};
