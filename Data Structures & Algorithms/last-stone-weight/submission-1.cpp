class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stones_sorted;
        for (int i : stones) {
            stones_sorted.push(i);
        }

        while(stones_sorted.size() > 1) {
            int first = stones_sorted.top();
            stones_sorted.pop();
            int second = stones_sorted.top();
            stones_sorted.pop();

            if (first != second) stones_sorted.push(first - second);
        }

        if (!stones_sorted.empty()) return stones_sorted.top();
        return 0;
    }
};
