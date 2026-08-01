class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            int heaviest = 0;
            int second = 0;

            for(int i = 0; i < stones.size(); i++) {
                if (stones[i] > stones[heaviest]) heaviest = i;
            }
            int index = heaviest;
            heaviest = stones[index];
            stones.erase(stones.begin() + index);

            for(int i = 0; i < stones.size(); i++) {
                if (stones[i] > stones[second]) second = i;
            }
            index = second;
            second = stones[index];
            stones.erase(stones.begin() + index);

            stones.push_back(max(heaviest, second) - min(heaviest, second));
        }
        if (!stones.empty()) return stones[0];
        return 0;
    }
};
