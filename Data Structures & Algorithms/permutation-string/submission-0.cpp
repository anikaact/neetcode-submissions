class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> letters(26);
        int l = 0;
        int r = s1.size() - 1;

        if (s2.size() < s1.size()) return false;

        for (char l : s1) {
            letters[l - 'a']--;
        }

        for (int i = 0; i < r; i++) {
            letters[s2[i] - 'a']++;
        }

        while (r < s2.size()) {
            letters[s2[r] - 'a']++;
            bool done = true;
            for (int l : letters) {
                if (l != 0) {
                    done = false;
                }
            }
            if (done) return done;
            else {
                letters[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return false;    
    }
};
