class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;

        for (int p : piles) {
            high = max(high, p);
        }

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int hours = 0;
            for (int pile : piles) {
                hours += (pile + mid - 1) / mid;
            }

            if (hours <= h) high = mid - 1;
            else low = mid + 1;
        }

        return low;
    }
};
