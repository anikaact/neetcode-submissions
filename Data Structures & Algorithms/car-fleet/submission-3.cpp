class Solution {
public:

//Input: target = 10, position = [0,1,4,7], speed = [1,2,2,1]

//first iteration: [1,3,6,8]
//second iteration: [2,5,8,9]
//third iteration: [3,7,10,10] (1 fleet: 2 cars at 10)
//fourth iteration: [4.9]
//fifth iteration: [5,11] (1 fleet: 1 car at 11)
//sixth iteration: array is length 1, +1 fleet

//Input: target = 10, position = [0,1,4,7], speed = [1,2,2,1]
//[9,9/2,3,3]

//input: target = 10, position = [6,8], speed = [3,2]
//[]
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pos_speed_data;
        for (int i = 0; i < position.size(); i++) {
            pos_speed_data.push_back({position[i], speed[i]});
        }
        //sort by position
        sort(pos_speed_data.begin(), pos_speed_data.end());

        //fleet calculations------------
        stack<double> time;
        //calculate time and push onto stack
        for (pair<double, double> data : pos_speed_data) {
            time.push((target - data.first) / data.second);
        }
        
        //keep popping off the stack while prev < top. when not true, add 1 to
        //fleet size and pop
        int fleet = 0;
        while (!time.empty()) {
            double prev = time.top();
            time.pop();
            while (!time.empty() && time.top() <= prev) {
                time.pop();
            }
            fleet++;
        }
        return fleet;
    }
};
