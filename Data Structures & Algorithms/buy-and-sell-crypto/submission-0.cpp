class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int smallest = 0;
        int maximum = 0;

        int left = 0;
        int right = 1;

        while (right < prices.size()) {
            maximum = max(maximum, prices[right] - prices[left]);
            if (prices[right] < smallest){
                smallest = prices[right];
                left = right;
                right++;
            } else if (prices[right] < prices[left]) {
                left = right;
                right++;
            } else {
                right++;
            }
        }

        return maximum;
    }
};
