class Solution {
public:
    int lengthOfLongestSubstring(string s) {
int left = 0;
        int right = 0;
        int maximum = 0;

        // Use 128 to cover all standard ASCII characters (spaces, symbols, etc.)
        vector<int> letters(128, 0);

        while (right < s.size()) {
            // If the character is already in our window, shrink from the left
            while (letters[s[right]] > 0) {
                letters[s[left]]--;
                left++;
            }

            // Include the current character in our window
            letters[s[right]]++;
            
            // Calculate maximum length before moving the right pointer
            maximum = max(maximum, right - left + 1);
            
            right++;
        }

        return maximum;
    }
};
